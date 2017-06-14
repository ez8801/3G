/* 
 * Serializer.cs
 * 
 * Writer : BMW
 * Date   : 2017-06-10
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using System.IO;
using System.Text;

/// <summary>
/// 
/// </summary>
/// <see cref="Deserializer"/>
public class Serializer
{
    private string m_folderPath = string.Empty;

    public Serializer(string folderPath)
    {
        m_folderPath = folderPath;
    }

    public void Serialize<T>(string tableName, Table<T> table) where T : ISerializable, new()
    {
        string fileName = string.Concat(tableName, ".bytes");
        string filePath = Path.Combine(m_folderPath, fileName);
        if (File.Exists(filePath))
            File.Delete(filePath);

        FileStream fileStream = new FileStream(filePath, FileMode.Create);
        BinaryWriter binaryWriter = new BinaryWriter(fileStream, Encoding.UTF8);
        binaryWriter.Write(table.Count);
        table.Export(binaryWriter);
    }
}