#include "../headers/Serializer.hpp"
#include "../headers/Data.hpp"

int	main(void)
{
	Data		*data = new Data();
	uintptr_t	dataSerialize;
	Data		*dataDeserialize;

	std::cout << "Original value maintained at Data: " << *data << std::endl;

	dataSerialize = Serializer::serialize(data);
	std::cout << "Value before cast from Data to uintptr_t: " << dataSerialize << std::endl;

	dataDeserialize = Serializer::deserialize(dataSerialize);
	std::cout << "Value after casting uintptr_t to Data: " << *dataDeserialize << std::endl;
	delete data;
}

int main2(void)
{
    // Create a Data object
    Data data;

    // Serialize the pointer to Data
    uintptr_t serialized = Serializer::serialize(&data);

    // Deserialize the serialized value
    Data* deserialized = Serializer::deserialize(serialized);

    // Check if deserialized pointer is equal to original pointer
    if (deserialized == &data)
    {
        std::cout << "Serialization and deserialization successful!\n";
    }
    else
    {
        std::cout << "Serialization and deserialization failed!\n";
    }
    return (0);
}