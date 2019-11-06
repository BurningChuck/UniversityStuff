#include <iostream>
#include <windows.h>
#include <thread>

int main(int argc, TCHAR* argv[])
{
	const DWORD processID = std::atoi(argv[1]);
	if (argc > 1)
	{
		std::cout << "process F get started " << std::endl;
	}
	// here go function
	std::this_thread::sleep_for(std::chrono::seconds(5));
	uint32_t answer = 42;

	uint32_t wParam = 0;
	if (answer <= WM_USER)
	{
		wParam = WM_USER + 1;
		answer += wParam;
	}
	const BOOL success = PostThreadMessageW(processID, answer, wParam, 0);
	if (success)
	{
		std::cout << "process F ended successfully " << std::endl;
	}
	else
	{
		std::cout << "process F ended with code " << GetLastError() << std::endl;
	}
	return 0;
}