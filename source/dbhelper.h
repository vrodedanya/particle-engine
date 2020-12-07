#ifndef DBHELPER_H
#define DBHELPER_H

#pragma once

#include <chrono>
#include <stdio.h>

class DBHelper
{
private:
	static std::chrono::system_clock::time_point st;
	DBHelper();
	DBHelper(const DBHelper&);
public:
	static double delta;

	static void begin() noexcept;
	static void end() noexcept;

// Functions with returning value
	template<typename RETURN, typename... TArgs1, typename... TArgs2>
	static RETURN check_exectime(RETURN(*func)(TArgs1...), TArgs2... MArgs) noexcept
	{
		fprintf (stderr, "[DBHelper]: Function with address %p begins\n", func);
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		RETURN buf = func(MArgs...);
		fprintf(stderr, "[DBHelper]: Function with address %p ends with duration: %f\n", func, static_cast<std::chrono::duration<double>>(std::chrono::system_clock::now() - start).count());
		return buf;
	}
// Methods with returning value
	template<typename RETURN, typename CLASS, typename... TArgs1, typename... TArgs2>
	static RETURN check_exectime(RETURN(CLASS::*func)(TArgs1...), CLASS* obj, TArgs2... MArgs) noexcept
	{
		fprintf (stderr, "[DBHelper]: Function with address %p begins\n", func);
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		RETURN buf = (obj->*func)(MArgs...);
		fprintf(stderr, "[DBHelper]: Function with address %p ends with duration: %f\n", func, static_cast<std::chrono::duration<double>>(std::chrono::system_clock::now() - start).count());
		return buf;
	}
// Functions without returning value
	template<typename... TArgs1, typename... TArgs2>
	static void check_exectime(void(*func)(TArgs1...), TArgs2... MArgs) noexcept
	{
		fprintf (stderr, "[DBHelper]: Function with address %p begins\n", func);
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		func(MArgs...);
		fprintf(stderr, "[DBHelper]: Function with address %p ends with duration: %f\n", func, static_cast<std::chrono::duration<double>>(std::chrono::system_clock::now() - start).count());
	}
// Methods without returning value
	template<typename CLASS, typename... TArgs1, typename... TArgs2>
	static void check_exectime(void(CLASS::*func)(TArgs1...), CLASS* obj, TArgs2... MArgs) noexcept
	{
		fprintf (stderr, "[DBHelper]: Function with address %p begins\n", func);
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		(obj->*func)(MArgs...);
		fprintf(stderr, "[DBHelper]: Function with address %p ends with duration: %f\n", func, static_cast<std::chrono::duration<double>>(std::chrono::system_clock::now() - start).count());
	}
};

#endif
