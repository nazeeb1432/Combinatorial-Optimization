#include<bits/stdc++.h>
using namespace std;

pair<pair<int, int>, pair<int, int>> line1, line2; // {{x1,y1}, {x2,y2}}
int x, y;

bool segments_intersect();
int direction(pair<int, int > p1, pair<int, int > p2, pair<int, int > p3);
bool on_segment(pair<int, int > p1, pair<int, int > p2, pair<int, int > p3);

int main(){
    freopen("input.txt", "r", stdin);
    cin >> x >> y;
    line1.first = {x,y};
    
    cin >> x >> y;
    line1.second = {x,y};

    cin >> x >> y;
    line2.first = {x,y};
    
    cin >> x >> y;
    line2.second = {x,y};
    
    (segments_intersect()) ? cout << "Two line segments intersect" << endl : cout << "Two line segments does not intersect" << endl;

    return 0;
}

bool segments_intersect(){
    int d1, d2, d3, d4;
    d1 = direction(line2.first, line2.second, line1.first);//  where is p4 from p1 with respect to p3
    d2 = direction(line2.first, line2.second, line1.second);// where is p4 from p2 with respect to p3
    d3 = direction(line1.first, line1.second, line2.first);// where is p2 from p3 with respect to p1
    d4 = direction(line1.first, line1.second, line2.second);// where is p2 from p4 with respect to p1

    if(((d1 > 0 and d2 < 0 ) or (d1 < 0 and d2 > 0)) and ((d3 > 0 and d4 < 0) or (d3 < 0 and d4 > 0))) return true;
    else if(d1 == 0 and on_segment(line2.first, line2.second, line1.first)) return true; 
    else if(d2 == 0 and on_segment(line2.first, line2.second, line1.second)) return true;
    else if(d3 == 0 and on_segment(line1.first, line1.second, line2.first)) return true; 
    else if(d4 == 0 and on_segment(line1.first, line1.second, line2.second)) return true; 
    else return false;
}


int direction(pair<int, int > p1, pair<int, int > p2, pair<int, int > p3){ // where is p2 from p3 with respect to p1
    pair<int, int> point1, point2;
    // x = x3 - x1
    point1.first = p3.first - p1.first;
    point1.second = p3.second - p1.second;
    point2.first = p2.first - p1.first;
    point2.second = p2.second - p1.second;

    // Cross Prod: x1y2 - x2y1 
    return (point1.first * point2.second) - (point2.first * point1.second);   
}

bool on_segment(pair<int, int > p1, pair<int, int > p2, pair<int, int > p3){
    if( 
        ( (min(p1.first, p2.first) <= p3.first) and (p3.first <= max(p1.first, p2.first)) ) and 
        ( (min(p1.second, p2.second) <= p3.second) and (p3.second <= max(p1.second, p2.second)) )){
            return true;
    }else return false;
}