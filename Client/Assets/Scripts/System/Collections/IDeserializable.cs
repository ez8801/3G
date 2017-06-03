
public interface IDeserializable
{
    void Deserialize(Deserializer deserializer);
    void Deserialize(JSONObject json);
}