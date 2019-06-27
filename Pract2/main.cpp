#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void get_time(tm * dt)
{
	string str;
	switch (dt->tm_wday) {
	case 0:str += "Воскресенье";break;
	case 1:str += "Понедельник";break;
	case 2:str += "Вторник";break;
	case 3:str += "Среда";break;
	case 4:str += "Четверг";break;
	case 5:str+= "Пятница";break;
	case 6:str += "Суббота";break;
	}

	switch (dt->tm_mon) {
	case 0:str += " Январь";break;
	case 1:str += " Февраль";break;
	case 2:str += " Март";break;
	case 3:str += " Апрель";break;
	case 4:str += " Май";break;
	case 5:str += " Июнь";break;
	case 6:str += " Июль";break;
	case 7:str += " Август";break;
	case 8:str += " Сентябрь";break;
	case 9:str += " Октябрь";break;
	case 10:str += " Ноябрь";break;
	case 11:str += " Декабрь";break;
	}
	cout << "Сейчас: "<< str << " " << dt->tm_mday << " " << dt->tm_hour << ":" << dt->tm_min << ":" << dt->tm_sec << " " << dt->tm_year+1900 << endl;
}


int main(){
string str;
time_t t = time(NULL);
tm * dt;
dt = localtime(&t);
get_time(dt);
return 0;
}