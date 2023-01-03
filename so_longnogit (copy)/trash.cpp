t_this *this()
{
	static t_this o;

	return (&o);
}
void teste()
{
	printf("object: %s\n", this()->ob->name);
}

void sdf()
{
	printf("object: %s\n", this()->ob->name);
}