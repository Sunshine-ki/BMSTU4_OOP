template <typename type>
std::shared_ptr<type[]> Vector<type>::allocate_memory(size_t count)
{
	std::shared_ptr<type[]> data = nullptr;
	try
	{
		data.reset(new type[count]);
	}
	catch (std::bad_alloc &err)
	{
		throw(error_memory(
			"При попытке инициализации вектора!",
			__FILE__, __LINE__, __func__));
	}
	return data;
}
