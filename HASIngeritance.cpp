#include <iostream>
#include <cstring>

using namespace std;

class Gun
{
private:
	int bullet;	//장정된 총알의 수

public:
	Gun(int bnum) : bullet(bnum)
	{
	}

	void Shot()
	{
		cout << "BBANG!" << endl;
		bullet--;
	}
};

class Police
{
private:
	int handcuffs;	//소유한 수갑의 수
	Gun * pistol;	//소유하고 있는 권총

public:
	Police(int bnum, int bcuff)
		:handcuffs(bcuff)
	{
		if(bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}

	void PutHandcuff()
	{
		cout <<"SNAP!" << endl;
		handcuffs--;
	}

	void Shot()
	{
		if(pistol == NULL)
			cout << "Hut BBANG!" << endl;
		else
			pistol->Shot();
	}

	~Police()
	{
		if(pistol != NULL)
			delete pistol;
	}
};

int main(void)
{
	Police pman(5, 3); 	//총알 5, 수갑 3
	pman.Shot();
	pman.PutHandcuff();

	Police pman2(0, 3);
	pman2.Shot();
	pman2.PutHandcuff();

	return 0;
}


