/* 
 * UIAdvancedGrid.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-25
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections.Generic;

public class UIAdvancedGrid : MonoBehaviour
{
    public delegate Transform CellForRowAtIndex(int index, GameObject contentView);
    public delegate int NumberOfRowsInGrid();

    // grid property
    public enum Arrangement	{ Horizontal, Vertical, }

	public Arrangement arrangement = Arrangement.Horizontal;
    public int maxPerLine = 1;
    public float cellWidth = 200f;
	public float cellHeight = 200f;
	
	public CellForRowAtIndex DataSource = null;	
    public NumberOfRowsInGrid Delegate = null;
	
	// panel
	private UIPanel panel = null;
    private UIScrollView scrollView = null;
	private Transform cachedTransform = null;
	
	// items
	private Dictionary<int, GameObject> m_Items = new Dictionary<int, GameObject>();
	private List<GameObject> m_ItemPool = new List<GameObject>();

    public int ObjectCount
    {
        get
        {
            int ret = 0;
            if (m_Items != null)
                ret += m_Items.Count;
            if (m_ItemPool != null)
                ret += m_ItemPool.Count;
            return ret;
        }
    }

    private GameObject lastObject;

    private struct ClipInfo
    {
        public Vector3 localPosition;
        public Vector2 clipOffset;

        public ClipInfo(Vector3 v3, Vector2 v4)
        {
            localPosition = v3;
            clipOffset = v4;
        }
    }

    //	
    private ClipInfo originClipInfo = new ClipInfo(Vector3.zero, Vector2.zero);
    private ClipInfo prevClipInfo = new ClipInfo(Vector3.zero, Vector2.zero);
    private ClipInfo focusClipInfo = new ClipInfo(Vector3.zero, Vector2.zero);

    private int firstVisibleItem = -1;
    private int lastVisibleItem = -1;

    private float clipFactor = 0.5f;

	//	
	private bool m_isDisableDragIfFits = false;
	private bool m_isFirstReposition = true;

    // BackUp Scroll
    private bool m_isKeepFocus = false;

    private bool m_isInitized = false;
    private bool m_isStart = false;

    public GameObject CellPrefab;


    //-------------------------------------------------------------------------
    //  MonoBehaviour
    //-------------------------------------------------------------------------
# region MonoBehaviour

    // start
	void Start()
	{
        m_isStart = true;
        Initialize();
        Reposition();
	}
	
	// update
	void Update()
	{
		if (prevClipInfo.localPosition != panel.transform.localPosition 
            || prevClipInfo.clipOffset != panel.clipOffset)
		{
			Reposition();

            prevClipInfo.localPosition = panel.transform.localPosition;            
            prevClipInfo.clipOffset = panel.clipOffset;
		}
	}

	void OnEnable()
	{
		m_isFirstReposition = true;
	}

# endregion MonoBehaviour

    private void Initialize()
    {
        if (m_isInitized)
            return;
        m_isInitized = true;

        panel = NGUITools.FindInParents<UIPanel>(gameObject);
        if (panel == null || panel.clipping == UIDrawCall.Clipping.None)
        {
            enabled = false;
            return;
        }

        scrollView = NGUITools.FindInParents<UIScrollView>(gameObject);
        if (scrollView == null)
        {
            enabled = false;
            return;
        }

        prevClipInfo.clipOffset = panel.clipOffset;
        prevClipInfo.localPosition = panel.transform.localPosition;

        originClipInfo.clipOffset = panel.clipOffset;
        originClipInfo.localPosition = panel.transform.localPosition;

        m_isDisableDragIfFits = scrollView.disableDragIfFits;

        cachedTransform = transform;
    }

    /// <summary>
    /// 지정된 인덱스의 오브젝트가 활성상태여부를 반환합니다
    /// </summary>
    public bool IsVisible(int index)
    {
        if (m_Items.ContainsKey(index))
            return true;        
        return false;
    }

    public Vector2 GetOffset(int index)
    {
        int x = 0;
        int y = 0;

        if (maxPerLine > 0)
        {
            for (int i = 0; i < index; i++)
            {
                if (++x >= maxPerLine && maxPerLine > 0)
                {
                    x = 0;
                    ++y;
                }
            }
        }
        else
        {
            // TODO : 
        }

        return new Vector2(x, y);
    }

    /// <summary>
    /// 캐싱된 오브젝트를 반환합니다. 만약 목록이 비어있으면 Null을 반환합니다.
    /// </summary>
    public GameObject GetCachedObject()
    {
        if (Util.IsNullOrEmpty(m_ItemPool))
            return null;

        GameObject go = m_ItemPool[0];
        m_ItemPool.RemoveAt(0);
        return go;
    }

    /// <summary>
    /// 지정된 인덱스의 오브젝트를 캐싱합니다.
    /// </summary>
    public void CacheObject(int ii)
    {
        if (m_Items.ContainsKey(ii))
        {
            GameObject go = m_Items[ii];
            m_Items.Remove(ii);

            go.name = string.Format("cached_{0}", go.name);
            go.SetActive(false);
            m_ItemPool.Add(go);
        }
    }

    private GameObject SetContentView(int ii, Vector3 vItemPos)
    {
        GameObject go = null;
        if (m_Items.ContainsKey(ii))
        {
            go = m_Items[ii];
            if (NGUITools.GetActive(go) == false)
                NGUITools.SetActive(go, true);
            go.transform.localPosition = vItemPos;
            go.transform.SetAsLastSibling();
        }
        else
        {
            go = GetCachedObject();
            if (go == null)
            {
                if (CellPrefab != null)
                    go = NGUITools.AddChild(gameObject, CellPrefab);
            }

            if (null != go)
            {
                if (NGUITools.GetActive(go) == false)
                    NGUITools.SetActive(go, true);
                go.name = ii.ToString();
                go.transform.SetAsLastSibling();
                go.transform.localPosition = vItemPos;

                DataSource(ii, go);

                m_Items.Add(ii, go);
            }
        }

        return go;
    }

    private void SetClip(UIPanel p, ClipInfo ci)
    {
        if (p == null)
            return;

        p.clipOffset = ci.clipOffset;
        p.transform.localPosition = ci.localPosition;
    }

	public void Clear(bool keepFocus = false)
	{
		for (Dictionary<int, GameObject>.Enumerator enumerator = m_Items.GetEnumerator(); enumerator.MoveNext();)
		{
			GameObject go = enumerator.Current.Value;

			go.SetActive(false);
			m_ItemPool.Add(go);
		}
		m_Items.Clear();

        if (keepFocus)
            m_isKeepFocus = true;
		if (panel != null)
		{
            focusClipInfo.localPosition = panel.transform.localPosition;
            focusClipInfo.clipOffset = panel.clipOffset;

            SetClip(panel, originClipInfo);
		}

		m_isFirstReposition = true;
	}

    public void ReloadVisibleRows()
    {
        if (panel == null)
            return;
        if (DataSource == null)
            return;
        
        for (Dictionary<int, GameObject>.Enumerator e = m_Items.GetEnumerator(); e.MoveNext(); )
        {
            DataSource(e.Current.Key, e.Current.Value);
        }
    }

	public void ReloadRowsAtIndex(int index)
	{
		if (panel == null)
			return;
		if (Delegate == null)
			return;
		if (index < 0 || index >= Delegate())
			return;

		GameObject go = null;
		if (m_Items.ContainsKey(index))
		{
			go = m_Items[index];
		}
		else
		{
			go = GetCachedObject();
            if (go == null)
            {
                if (CellPrefab != null)
                {
                    go = NGUITools.AddChild(gameObject, CellPrefab);
                }
            }

            if (null != go)
            {
                go.name = index.ToString();
                m_Items.Add(index, go);
            }
		}

        if (null != go)
        {
            if (NGUITools.GetActive(go) == false)
                NGUITools.SetActive(go, true);
            DataSource(index, go);
        }
	}

	// reposition item 기록 아이템 드로우
	public void Reposition()
	{
		if (panel == null)
			return;
		if (Delegate == null)
			return;
		
        if (m_isKeepFocus)
        {
            m_isKeepFocus = false;

            SetClip(panel, focusClipInfo);
        }

		float fHalfCellWidth = cellWidth * 0.5f;
		float fHalfCellHeight = cellHeight * 0.5f;

        Vector2 size = panel.GetViewSize();
        float fHalfClipWidth = size.x * clipFactor;
		float fMinClipX = panel.clipOffset.x - fHalfClipWidth - cachedTransform.localPosition.x;
		float fMaxClipX = panel.clipOffset.x + fHalfClipWidth - cachedTransform.localPosition.x;

        float fHalfClipHeight = (size.y + cellHeight) * clipFactor;
		float fMinClipY = panel.clipOffset.y - fHalfClipHeight - cachedTransform.localPosition.y;
		float fMaxClipY = panel.clipOffset.y + fHalfClipHeight - cachedTransform.localPosition.y;
		
		int nItemCount = Delegate();

		int x = 0;
		int y = 0;

		bool bAllShow = true;
        bool bLastObject = false;
        
        firstVisibleItem    = -1;
        lastVisibleItem     = -1;
		for (int ii = 0; ii < nItemCount; ++ii)
		{
			Vector3 vItemPos = 			
				(arrangement == Arrangement.Horizontal) ?
				new Vector3(cellWidth * x, -cellHeight * y, -1.0f) :
				new Vector3(cellWidth * y, -cellHeight * x, -1.0f);
			
			if (++x >= maxPerLine && maxPerLine > 0)
			{
				x = 0;
				++y;
			}
			
			bool bVisible = true;
			if (vItemPos.x - fHalfCellWidth > fMaxClipX) bVisible = false;
			if (vItemPos.x + fHalfCellWidth < fMinClipX) bVisible = false;
			if (vItemPos.y - fHalfCellHeight > fMaxClipY) bVisible = false;
			if (vItemPos.y + fHalfCellHeight < fMinClipY) bVisible = false;

            if (bVisible)
            {
                if (firstVisibleItem == -1)
                    firstVisibleItem = ii;
                lastVisibleItem = Mathf.Max(lastVisibleItem, ii);
            }

            // 스크롤 영역을 위해 마지막 오브젝트는 활성화
            if (ii == 0 || ii == nItemCount - 1)
            {
                bVisible = true;
                bLastObject = true;
            }
			
			if (bVisible)
			{
                GameObject contentView = SetContentView(ii, vItemPos);
                if (bLastObject)
                {
                    lastObject = contentView;
                }
			}
			else
			{
                CacheObject(ii);
				bAllShow = false;
			}
		}
        
        if (m_isDisableDragIfFits)
            scrollView.disableDragIfFits = bAllShow;

		if (m_isFirstReposition)
		{
        	Bounds bounds = NGUIMath.CalculateRelativeWidgetBounds(panel.cachedTransform, cachedTransform);
        	panel.ConstrainTargetToBounds(cachedTransform, ref bounds, true);		
			m_isFirstReposition = false;

            // ConstrainTargetToBounds에서 position을 변경해 버리기 때문에 다시 위치를 조절해야됨
            Reposition();	
		}
	}

    public void FocusToPosition(int position)
    {
        if (m_isStart == false)
            Initialize();

        if (panel == null)
            return;

        int ItemCount = (Delegate != null) ? Delegate() : 0;
        if (ItemCount < position)
            return;

        if (scrollView != null)
            scrollView.DisableSpring();

        Vector2 offset = GetOffset(position);
        panel.clipOffset = new Vector2(
            originClipInfo.clipOffset.x
            , originClipInfo.clipOffset.y - (offset.y * cellHeight));
        panel.transform.SetLocalPositionY(originClipInfo.localPosition.y + (offset.y * cellHeight));

        m_isFirstReposition = true;
        // Reposition();
    }

    /// <summary>
    /// UIGrid 하위의 오브젝트를 갱신하고 포커스를 첫번째 오브젝트로 설정합니다.
    /// </summary>
    public void ReloadData()
    {
        int prevFirstVisibleItem = firstVisibleItem;
        int prevLastVisibleItem = lastVisibleItem;
        int prevObjectCount = ObjectCount;

        // 첫번째 오브젝트 캐싱
        CacheObject(0);

        // 스크롤 영역을 위해 켜두었던 오브젝트를 비활성화
        if (NGUITools.GetActive(lastObject) == true)
        {
            NGUITools.SetActive(lastObject, false);
        }

        FocusToPosition(0);
        Reposition();

        if (IsBetween(firstVisibleItem, prevFirstVisibleItem, prevLastVisibleItem)
            || IsBetween(lastVisibleItem, prevFirstVisibleItem, prevLastVisibleItem))
        {
            // 최초로 호출되는 경우 제외
            if (prevObjectCount > 0)
                ReloadVisibleRows();
        }
    }

    private bool IsBetween(int value, int start, int end)
    {
        return (start <= value && end >= value);            
    }

    /// <summary>
    /// 클립 계수를 설정합니다. (Default: 0.5)
    /// (0.5 ~ 1)
    /// </summary>
    public void SetClipFactor(float factor)
    {
        clipFactor = Mathf.Clamp(factor, 0.5f, 1f);
    }
}