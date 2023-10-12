#include <iostream>

int main(int argc, char** argv)
{
	int n = 0;
	std::cin >> n;

	for (int i = 0; i < 32; ++i)				
	{											
		std::cout << (n >> (31 - i) & 1);		
	}											

	std::cout << std::endl;

	int a = 0;

	for (int i = 0; i < 32; ++i)
	{
		if ((n >> i & 1) == 1)
		{
			++a;
		}
	}

	if (a == 1)
	{
		for (int i = 0; i < 32; ++i)
		{
			std::cout << (n >> (31 - i) & 1);
		}

		return EXIT_SUCCESS;
	}

	int f_num = 0;
	int b = 0;

	for (int i = 0; i < 32; ++i)				
	{											
		if (b == 0)							
		{										
			std::cout << (n >> (31 - i) & 1);	
			b = (n >> (31 - i) & 1);		
			++f_num;						
		}										
	}											

	int l_num = 31;

	for (int i = 0; i < 32; ++i)				
	{											
		if ((n >> i & 1) != 1)					
		{										
			--l_num;					
		}										
		else								
		{										
			i = 32;								
		}										
	}											

	n = ~n;

	for (int i = f_num; i < l_num; ++i)	
	{											
		std::cout << (n >> (31 - i) & 1);		
	}											

	n = ~n;

	for (int i = l_num; i < 32; ++i)			
	{											
		std::cout << (n >> (31 - i) & 1);		
	}											

	return EXIT_SUCCESS;
}