#include<iostream>
#include<vector>

using namespace std;

struct point {
    int x;
    int y;
};
void robotTraversal(int a[][10], int x, int y, vector<vector<point> >& lists, vector<point> path, int& index) ;
int main()
{
    int grid[10][10];
    int x = 10, y = 10;
    point p;
    
    vector<point> path;
    vector<vector<point> > lists;
    int index = 0;
    robotTraversal(grid, x, y, lists, path, index);
    cout<<"Total path:"<<index<<endl;
    cout<<"Listing paths"<<endl;
    for (int i = 0; i < lists.size(); i++) {
        vector<point> temp = lists[i];
        for (int j = 0; j < temp.size(); j++) {
            point p = temp[j];
            cout<<"X:"<<p.x<<"Y:"<<p.y;
        }
        cout<<endl;
    }
}

void robotTraversal(int a[][10], int x, int y, vector<vector<point> >& lists, vector<point> path, int& index) {
    if (x == 0 && y == 0) {
        lists.push_back(path);
        index++;
        return;
    }

    if (x < 0 || y < 0) {
        return;
    }

    point p;
    p.x = x;
    p.y = y;
    path.push_back(p);
    robotTraversal(a, x - 1, y, lists, path, index);
    robotTraversal(a, x , y - 1, lists, path, index);
}
