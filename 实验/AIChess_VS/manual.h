#pragma once
#ifndef manual
#define manual

#include"AIChess_VS.h"	
using namespace std;

vector <int> al51 = { 1,1,1,1,1 };//0x7f
vector <int> ah41 = { 0,1,1,1,1,0 };//0x7f
vector <int> ac41 = { 1,0,1,1,1 };//12
vector <int> ac42 = { 1,1,1,0,1 };//12
vector <int> ac43 = { 0,1,1,1,1,2 };//12
vector <int> ac44 = { 2,1,1,1,1,0 };//12
vector <int> ac45 = { 1,1,0,1,1 };//12
vector <int> ah31 = { 0,1,1,1,0 };//8
vector <int> ah32 = { 1,0,1,1 };//8
vector <int> ah33 = { 1,1,0,1 };//8
vector <int> am31 = { 0,0,1,1,1,2 };//4
vector <int> am32 = { 2,1,1,1,0,0 };//4
vector <int> am33 = { 0,1,0,1,1,2 };//4
vector <int> am34 = { 2,1,1,0,1,0 };//4
vector <int> am35 = { 0,1,1,0,1,2 };//4
vector <int> am36 = { 2,1,0,1,1,0 };//4
vector <int> am37 = { 1,0,0,1,1 };//4
vector <int> am38 = { 1,1,0,0,1 };//4
vector <int> am39 = { 1,0,1,0,1 };//4
vector <int> am310 = { 2,0,1,1,1,0,2 };//4
vector <int> ah21 = { 0,0,1,1,0,0 };//2
vector <int> ah22 = { 0,1,0,1,0 };//2
vector <int> ah23 = { 1,0,0,1 };//2

vector <int> dl51 = { 2,2,2,2,2 };
vector <int> dh41 = { 0,2,2,2,2,0 };
vector <int> dc41 = { 2,0,2,2,2 };
vector <int> dc42 = { 2,2,2,0,2 };
vector <int> dc43 = { 0,2,2,2,2,1 };
vector <int> dc44 = { 1,2,2,2,2,0 };
vector <int> dc45 = { 2,2,0,2,2 };
vector <int> dh31 = { 0,2,2,2,0 };
vector <int> dh32 = { 2,0,2,2 };
vector <int> dh33 = { 2,2,0,2 };
vector <int> dm31 = { 0,0,2,2,2,1 };
vector <int> dm32 = { 1,2,2,2,0,0 };
vector <int> dm33 = { 0,2,0,2,2,1 };
vector <int> dm34 = { 1,2,2,0,2,0 };
vector <int> dm35 = { 0,2,2,0,2,1 };
vector <int> dm36 = { 1,2,0,2,2,0 };
vector <int> dm37 = { 2,0,0,2,2 };
vector <int> dm38 = { 2,2,0,0,2 };
vector <int> dm39 = { 2,0,2,0,2 };
vector <int> dm310 = { 1,0,2,2,2,0,1 };
vector <int> dh21 = { 0,0,2,2,0,0 };
vector <int> dh22 = { 0,2,0,2,0 };
vector <int> dh23 = { 2,0,0,2 };
#endif // !manual
