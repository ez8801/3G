#define ENABLE_CRYPTO

using System;
using System.Text;

public static class Crypto
{
    private static string Key
    {
        get
        {
            return m_key;
        }
        set
        {
            m_key = value;
        }
    }
    private static string m_key = null;

    /// <summary>
    /// 지정된 문자열을 Base64형태로 변환하여 반환합니다.
    /// </summary>
    public static string EncryptBase64(string plainText)
    {
        if (string.IsNullOrEmpty(plainText) || string.IsNullOrEmpty(m_key))
            return plainText;

#if ENABLE_CRYPTO
        byte[] bytes = Encoding.UTF8.GetBytes(plainText);
        byte[] cryptedBytes = new byte[bytes.Length];

        for (int i = 0; i < bytes.Length; i++)
        {
            char ch = (char)bytes[i];
            int keyIndex = (i % m_key.Length) - 1;

            char keyCh = m_key[keyIndex < 0 ? m_key.Length - 1 : keyIndex];
            ch = (char)((int)ch + (int)keyCh);

            cryptedBytes[i] = (byte)ch;
        }

        return Convert.ToBase64String(cryptedBytes);
#else
        return plainText;
#endif
    }

    /// <summary>
    /// 지정된 Base64형태의 문자열을 일반 문자열 형태로 변환하여 반환합니다.
    /// </summary>
    public static string DecryptBase64(string encryptedText)
    {
        if (string.IsNullOrEmpty(encryptedText) || string.IsNullOrEmpty(m_key))
            return encryptedText;

#if ENABLE_CRYPTO
        byte[] encryptedBytes = Convert.FromBase64String(encryptedText);        
        byte[] decryptedBytes = new byte[encryptedBytes.Length];

        for (int i = 0; i < encryptedBytes.Length; i++)
        {
            char ch = (char)encryptedBytes[i];
            int keyIndex = (i % m_key.Length) - 1;

            char keyCh = m_key[keyIndex < 0 ? m_key.Length - 1 : keyIndex];
            ch = (char)((int)ch - (int)keyCh);

            decryptedBytes[i] = (byte)ch;
        }

        return Encoding.UTF8.GetString(decryptedBytes);
#else
        return encryptedText;
#endif
    }
}
