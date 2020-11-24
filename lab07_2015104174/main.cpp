#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
// Get random socre
#include <ctime>
#include <cstdlib>

void ComputeAverageNGrade(int numOfStudents,int prs[], int rep[], int mid[], int fnl[], double average[], char grade[]) {
	for (int i = 0; i < numOfStudents; i++) {
		average[i] = double((5 * prs[i] + 35 * rep[i] + 25 * mid[i] + 35 * fnl[i]) / 100);
		if (average[i] > 90) {
			grade[i] = 'A';
		}
		else if (average[i] > 80) {
			grade[i] = 'B';
		}
		else if (average[i] > 70) {
			grade[i] = 'C';
		}
		else if (average[i] > 60) {
			grade[i] = 'D';
		}
		else {
			grade[i] = 'F';
		}
	}
	return;
}

int GetRand(int min, int max)
{
	static int flag = true;
	if (flag) { // 처음 한번만 seed를 세팅한다. 
		srand((unsigned)time(NULL));
		flag = false;
	}
	int temp = rand() % ((max + 1) - min) + min;
	return(temp);
}


// 이름을 입력 받아서 리턴한다.
string GetName(int num) {
	string name;
	cout << "\n\t" << num << "번째 학생의 이름을 입력하시오--> ";
	cin >> name;
	return name;
}



//하나의 정수를 입력하여 리턴하는 함수 정의
int GetData(int order, string mssg) {
	cout << "\t" << order << "번째 학생의 " << mssg << "를 입력하시오--> ";
	int num;
	cin >> num;
	return num;
}


void GetStudentInfo(int indx, string& name, int& mid, int& fnl) {
	name = GetName(indx);
	mid = GetData(indx, "중간고사 점수");
	fnl = GetData(indx, "기말고사 점수");
}


void GetStudentInfo(int indx, string& name, int& repo, int& pst, int& mid, int& fnl) {

	cout << "\t " << indx << "번째 학생의 이름 입력-->";
	cin >> name;
	mid = GetRand(50, 100);
	repo = GetRand(50, 100);
	pst = GetRand(50, 100);
	fnl = GetRand(50, 100);

}

void GetClassInfo(int num, string name[], int repo[], int pst[], int mid[], int fnl[]) {
	for (int i = 0; i < num; i++)
	{
		GetStudentInfo(i, name[i], repo[i], pst[i], mid[i], fnl[i]);
	}
}

// 2번
void DisplayStudentInfo(int indx, string name, int rep, int prs, int mid, int fnl) {
	cout.fill(' ');
	cout << "\t " << setw(5) << indx << ": " << setw(5) << name << setw(5) << rep << setw(5) << prs << setw(5) << mid << setw(5) << setprecision(1) << fixed << fnl << endl;
}

// 4번
void DisplayStudentInfo(int indx, string name, int rep, int prs, int mid, int fnl, double average, char grade) {
	cout.fill(' ');
	cout << "\t " << setw(5) << indx << ": " << setw(5) << name << setw(5) << rep << setw(5) << prs << setw(5) << mid << setw(5) << fnl
		<< setw(5) << average << setw(5) << grade << endl;
}


//5
#define WIDTH 10
void DisplayStudentInfo(double flg, int num, string name, int prs, int rep, int mid, int fnl, double average, char grade) {
	cout << "\t*" << setw(8 * WIDTH + 1) << setfill('-') << "*\n";
	cout.fill(' ');
	cout << "\t|" << setw(WIDTH - 2) << num << " |"
		<< setw(WIDTH - 2) << name << " |"
		<< setw(WIDTH - 2) << prs << " |"
		<< setw(WIDTH - 2) << rep << " |"
		<< setw(WIDTH - 2) << mid << " |"
		<< setw(WIDTH - 2) << fnl << " |"
		<< setw(WIDTH - 2) << noshowpoint << fixed << setprecision(2) << average << " |" 
		<< setw(WIDTH - 2) << grade << " |"
		<< endl;
	return;
}
void DisplayBottom() {
	cout << "\t*" << setw(8 * WIDTH + 1) << setfill('-') << "*\n";
	cout.fill(' ');
	return;
}

void DisplayTitle(string title[]) {
	cout << "\t*" << setw(8 * WIDTH + 1) << setfill('-') << "*\n";
	cout.fill(' ');
	cout << "\t|" << setw(WIDTH - 2) << title[0] << " |"
		<< setw(WIDTH - 2) << title[1] << " |"
		<< setw(WIDTH - 2) << title[2] << " |"
		<< setw(WIDTH - 2) << title[3] << " |"
		<< setw(WIDTH - 2) << title[4] << " |"
		<< setw(WIDTH - 2) << title[5] << " |"
		<< setw(WIDTH - 2) << title[6] << " |"
		<< setw(WIDTH - 2) << title[7] << " |" << endl;
	return;

}

//2
void DisplayClassInfo(int num, string name[],int pre[], int rep[],  int mid[], int fnl[]) {

	for (int i = 0; i < num; i++) {
		DisplayStudentInfo(i, name[i], pre[i], rep[i], mid[i], fnl[i]);
	}
}

void DisplayClassInfo(int num, string name[], int pre[], int rep[], int mid[], int fnl[], double average[], char grade[]) {
	for (int i = 0; i < num; i++) {
		DisplayStudentInfo(i, name[i], pre[i], rep[i], mid[i], fnl[i], average[i], grade[i]);
	}
}

// formated display
void DisplayClassInfo(int num, string title[], string name[], int pre[], int rep[], int mid[], int fnl[]
	, double average[], char grade[]) {
	DisplayTitle(title); // display item name
	for (int i = 0; i < num; i++) {
		DisplayStudentInfo(1.0, i, name[i], pre[i], rep[i], mid[i], fnl[i]
			, average[i], grade[i]);
	}
	DisplayBottom();
}


#define MAXCOMMANDS 5
int GetCommand() {
	int select;
	while (1) {
		cout << "\t=" << setw(41) << setfill('=') << "=\n";
		cout << "\t|" << left << setw(40) << setfill(' ') << "  0: Quit" << "|\n";
		cout << "\t|" << left << setw(40) << setfill(' ') << "  1: 학생정보와 점수 입력" << "|\n";
		cout << "\t|" << left << setw(40) << setfill(' ') << "  2: 학생정보 화면 출력" << "|\n";
		cout << "\t|" << left << setw(40) << setfill(' ') << "  3: 성적 계산" << "|\n";
		cout << "\t|" << left << setw(40) << setfill(' ') << "  4: 성적 포함 학생정보 화면 출력" << "|\n";
		cout << "\t|" << left << setw(40) << setfill(' ') << "  5: 성적 포함 학생정보 형식화된 출력" << "|\n";
		cout << "\t=" << right << setw(41) << setfill('=') << "=\n";
		cout << "\t  Select a function --> ";

		if (cin.fail() || !(cin >> select) || select < 0 || select>MAXCOMMANDS)	// input fail or input value is out of bound
		{
			cout << "\t    ### Invalid Command Number. Select again  ####" << endl;
			cin.clear();	//clear flag
			cin.ignore(INT_MAX, '\n');	//empty input buffer
		}
		else {
			cin.clear();  // clear flag
			cin.ignore(INT_MAX, '\n');  // empty input buffer
			return select;
		}
	}
}


int main()
{
	const int numOfStudents = 5;
	string name[numOfStudents];
	int pst[numOfStudents];
	int repo[numOfStudents];
	int mid[numOfStudents];
	int fnl[numOfStudents];
	double average[numOfStudents];
	char grade[numOfStudents];

	string title[8] = { "순번","이름","출석", "과제", "중간","기말","평균","학점" };


	int selection;
	while (1)
	{
		selection = GetCommand();
		switch (selection) {
		case 0:
			return 1;
		case 1:  // read class info
			GetClassInfo(numOfStudents, name, repo, pst,  mid, fnl);
			break;
		case 2: //display class info
			DisplayClassInfo(numOfStudents, name, pst, repo, mid, fnl);
			break;
		case 3:
			ComputeAverageNGrade(numOfStudents, pst, repo, mid, fnl, average, grade);
			break;
		case 4:
			DisplayClassInfo(numOfStudents, name,pst, repo, mid, fnl, average, grade);
			break;
		case 5:
			DisplayClassInfo(numOfStudents, title, name, pst, repo,  mid, fnl, average, grade);
			break;
		default:
			cout << "\t 잘못된 문제 번호입니다 " << endl;
		}
	}
}



