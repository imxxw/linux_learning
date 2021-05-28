#include "person.h"
#include "person_wrapper.h"
#include <assert.h>

void *person_create(const char *name, int age)
{
	return new Person(name, age);
}

void person_destroy(void *p)
{
	assert(p);
	delete static_cast<Person *>(p);
}

int person_get_age(void *p)
{
	assert(p);
	return static_cast<Person *>(p)->GetAge();
}

const char *person_get_name(void *p)
{
	assert(p);
	return static_cast<Person *>(p)->GetName();
}