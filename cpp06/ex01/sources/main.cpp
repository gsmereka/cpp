#include "../headers/Serializer.hpp"
#include "../headers/Data.hpp"

int	main(void)
{
	Data		*data = new Data();
	uintptr_t	dataSerialize;
	Data		*dataDeserialize;

	std::cout << "Original: " << *data << std::endl;

	dataSerialize = Serializer::serialize(data);
	std::cout << "Serialized to uintptr_t: " << dataSerialize << std::endl;

	dataDeserialize = Serializer::deserialize(dataSerialize);
	std::cout << "Deserialized uintptr_t to Data: " << *dataDeserialize << std::endl;

    if (dataDeserialize == data)
    {
        std::cout << "\nSerialization and deserialization successful!\n";
    }
    else
    {
        std::cout << "Serialization and deserialization failed!\n";
    }
	delete data;
}
