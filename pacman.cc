#include<iostream>
#include<vector>

using namespace std;
struct pos_t {
	int x;
	int y;
};

class pacMan {

private:
    int board[10][10];
    pos_t goal;
    pos_t start;
    vector<pos_t> wall;
    bool initOuterWall();
    bool initInnerWall();
    bool buildWall();

public:
    pacMan(int x,int y);
    ~pacMan();
    void printWall();
    void printBoard();
}; 

pacMan::pacMan(int x, int y) {

	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			board[i][j] = 0;
		}
	}
	initOuterWall();
	initInnerWall();
	buildWall();
	goal.x = x;
	goal.y = y;

	start.x = 0;
	start.y = 5;
}

bool
pacMan::initOuterWall() {
int n = 10;
pos_t pos;

	for(int i = 0; i < 10;i++) {
		for(int j = 0; j < n ;j++) {
			pos.x = i;
			pos.y = j;
            if(j == 5)
                pos.y = 0;

			wall.push_back(pos);
			if(j == 9) {
				n = 0;
				continue;
			}
		}
		if(i != 0) {
			pos.x = i;
			pos.y = 0;
			wall.push_back(pos);
		}
	}
return true;
}
bool
pacMan::initInnerWall() {
pos_t pos;

	pos.x = 2;
	pos.y = 2;
	wall.push_back(pos);
	pos.x = 2;
	pos.y = 3;
	wall.push_back(pos);
	pos.x = 2;
	pos.y = 4;
	wall.push_back(pos);
	pos.x = 2;
	pos.y = 5;
	wall.push_back(pos);
	pos.x = 3;
	pos.y = 2;
	wall.push_back(pos);
	pos.x = 3;
	pos.y = 4;
	wall.push_back(pos);
	pos.x = 4;
	pos.y = 2;
	wall.push_back(pos);
	pos.x = 4;
	pos.y = 4;
	wall.push_back(pos);
	pos.x = 4;
	pos.y = 5;
	wall.push_back(pos);
	pos.x = 5;
	pos.y = 2;
	wall.push_back(pos);
	pos.x = 5;
	pos.y = 4;
	wall.push_back(pos);

return true;

}

bool
pacMan::buildWall() {
	for(int i = 0; i < wall.size();i++) {
		board[wall[i].x][wall[i].y] = 1;
	}
    return true;
}

void
pacMan::printBoard() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout<<board[i][j]<<"\t";
        }
        cout<<endl;
    }
    /*
    for(int i = 0; i < 10; i++) {
        cout<<i<<"\t";
    }
    cout<<endl;

    for(int i = 0; i < 10;i++) {
        cout<<"_______";
    }
    */
}

void
pacMan::printWall() {
cout<<"The wall is:"<<endl;
	for(int i = 0; i < wall.size();i++) {
		cout<<wall[i].x;
		cout<<wall[i].y;
		cout<<endl;
	}
}

pacMan::~pacMan()
{
}

int main()
{
	pacMan pac(6,7);
//	pac.printWall();
    pac.printBoard();
return 0;
}
