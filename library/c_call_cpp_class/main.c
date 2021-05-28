#include <stdio.h>
#include "person_wrapper.h"

int main()
{
	void *p = person_create("kevin", 18);
	const char *name = person_get_name(p);
	int age = person_get_age(p);
	person_destroy(p);
	printf("name=%s, age=%d\n", name, age);
}