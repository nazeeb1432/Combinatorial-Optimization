#include<bits/stdc++.h>
using namespace std;

int num_vertex;
double x, y;
vector<pair<double, double>> q;
vector<pair<pair<double, double>, double>> tmp; // {{{x,y}, slope}, ...}
vector<pair<pair<double, double>,double>> s; // stack  

/*
    /  
    ------   p1.p2 = p1p2cos theta
    arc cos(p1.p2 / p1p2)

*/

double get_angle(pair<double, double> p0, pair<double, double> p1, pair<double, double> p2);
bool is_non_left_turn(pair<double, double> p0, pair<double, double> p1, pair<double, double> p2);
bool compare(pair<int, int> p1, pair<int, int> p2);


int main(){

    freopen("convex.txt", "r", stdin);
    cin >> num_vertex;
    for(int i = 0; i < num_vertex; ++i){
        cin >> x >> y;
        q.push_back({x,y});
        tmp.push_back({{x,y},0.0});
    }

    //sort(q.begin(), q.end(), compare); -> nlogn

    for(int i = 0; i < num_vertex; ++i){
        for(int j = i+1; j < num_vertex; ++j){
            if(tmp[i].first.second > tmp[j].first.second){
                auto temp = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = temp;
            }else if(tmp[i].first.second == tmp[j].first.second){
                if(tmp[i].first.first > tmp[j].first.first){
                    auto temp = tmp[i];
                    tmp[i] = tmp[j];
                    tmp[j] = temp;
                }
            }
        }
    }

    for(int i = 0; i < num_vertex; ++i){
        cout << tmp[i].first.first << "," << tmp[i].first.second << ", slope: " << tmp[i].second << endl;
    }

    for(int i = 1; i < num_vertex; ++i){
        double slope = atan((tmp[i].first.second - tmp[0].first.second) / (tmp[i].first.first - tmp[0].first.first));
        if(slope < 0){
            slope = M_PI - fabs(slope);
        }
        tmp[i].second = slope;
    }

    for(int i = 1; i < num_vertex; ++i){
        for(int j = i+1; j < num_vertex; ++j){
            if(tmp[i].second > tmp[j].second){
                auto temp = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = temp;
            }else if(tmp[i].second == tmp[j].second){
                //double minimum = min(tmp[i].first.first, tmp[j].first.first);
                /*euclidean norm*/
                double dist1 = sqrt(pow((tmp[i].first.second - tmp[0].first.second),2) + pow((tmp[i].first.second - tmp[0].first.second),2)); 
                double dist2 = sqrt(pow((tmp[j].first.second - tmp[0].first.second),2) + pow((tmp[j].first.second - tmp[0].first.second),2)); 
                int idxToBeRemoved; 
                if(dist1 < dist2){
                    idxToBeRemoved = i;
                }else{
                    idxToBeRemoved = j;
                }
                auto it = next(tmp.begin(), idxToBeRemoved);
                tmp.erase(it);
                num_vertex--;
            }
        }
    }

    cout << endl << endl;

    // for(int i = 0; i < num_vertex; ++i){
    //     cout << tmp[i].first.first << "," << tmp[i].first.second << ", slope: " << tmp[i].second << endl;
    // }

    /*if more than one point has the same angle then remove all but the one that is farthest from p0*/

    // for(int i = 1; i < num_vertex; ++i){
    //     for(int j = i + 1; j < num_vertex; ++j){
    //         if(tmp[i].second == tmp[j].second){

    //         }
    //     }
    // }   

    for(int i = 0; i < 3; ++i) s.push_back(tmp[i]);

    for(int i = 3; i < num_vertex; ++i){        
        while(1){
            auto idx = s.size() - 1;
            pair<double, double> top = s[idx].first;
            pair<double, double> next_to_top = s[idx-1].first;
            pair<double, double> p_i = tmp[i].first;
            if(!is_non_left_turn(top, next_to_top, p_i)){
                break;
            }
            s.pop_back();
        }
        s.push_back(tmp[i]);
    }

    cout << "Points of the polygon using Graham Scan:" << endl;
    //Plot points in Graph && Check
    for(auto e : s){
        cout << endl<<"(" <<e.first.first << ", " << e.first.second <<")" << endl;
    }

    return 0;
}

double get_angle(pair<double, double> p0, pair<double, double> p1, pair<double, double> p2){
    // p0p1, p0p2
    pair<double, double> vec1, vec2;
    vec1.first = p1.first - p0.first;
    vec1.second = p1.second - p0.second;
    vec2.first = p2.first - p0.first;
    vec2.second = p2.second - p0.second;

    /*dot prod = x1*x2 + y1*y2 */

    double dot_prod = vec1.first * vec2.first + vec1.second * vec2.second;
    double magnitude1 = sqrt(pow(vec1.first,2) + pow(vec1.second,2)); // (x1^2 + y1^2) ^ .5
    double magnitude2 = sqrt(pow(vec2.first,2) + pow(vec2.second,2)); 

    double angle = acos(dot_prod / (magnitude1 * magnitude2));
    return angle;
}

bool is_non_left_turn(pair<double, double> p0, pair<double, double> p1, pair<double, double> p2){
    /*
    top -> p1
    next_to_top -> p0
    p[i] -> p2

    (i - ntp) * (top - ntp)
    */
    double x1,x2,y1,y2;
    x1 = p1.first - p0.first;
    x2 = p2.first - p0.first;
    
    y1 = p1.second - p0.second;
    y2 = p2.second - p0.second;

    double cross_prod = x1*y2 - x2*y1;
    
    return (cross_prod >= 0); // if false -> left turn
}

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second < p2.second;
}