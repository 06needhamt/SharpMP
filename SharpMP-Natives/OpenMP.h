#pragma once
#include "omp.h"
#include "ScheduleKind.h"

static_assert(sizeof(int) == 4, "This Library must be compiled in 64-Bit mode");
static_assert(sizeof(void*) == 8, "This Library must be compiled in 64-Bit mode");

extern "C" {
	_declspec(dllexport) void SetNumThreads(int threads);
		_declspec(dllexport) void SetDynamic(int dynamic);
		_declspec(dllexport) void SetNested(int nested);
		_declspec(dllexport) void SetMaxActiveLevels(int maxLevels);
		_declspec(dllexport) void SetSchedule(ScheduleKind schedule, int chunkSize);
		_declspec(dllexport) int GetNumThreads();
		_declspec(dllexport) int GetDynamic();
		_declspec(dllexport) int GetNested();
		_declspec(dllexport) int GetMaxThreads();
		_declspec(dllexport) int GetThreadNum();
		_declspec(dllexport) int GetNumProcs();
		_declspec(dllexport) int InParralel();
		_declspec(dllexport) int InFinal();
		_declspec(dllexport) int GetActiveLevel();
		_declspec(dllexport) int GetLevel();
		_declspec(dllexport) int GetAncestorThreadNum(int threadNum);
		_declspec(dllexport) int GetTeamSize(int team);
		_declspec(dllexport) int GetThreadLimit();
		_declspec(dllexport) int GetMaxActiveLevels();
		_declspec(dllexport) void GetSchedule(void* kind, int* chunkSize);
		_declspec(dllexport) int GetMaxTaskPriority();
}