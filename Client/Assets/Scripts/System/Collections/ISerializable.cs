/* 
 * ISerializable.cs
 * 
 * Writer : BMW
 * Date   : 2017-06-10
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using System.IO;

public interface ISerializable
{
    void Serialize(BinaryWriter binaryWriter);
}