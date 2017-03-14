/**
   Given a collection of intervals, merge all overlapping intervals.
   For example,
    Given [1,3],[2,6],[8,10],[15,18],
    return [1,6],[8,10],[15,18]. 
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

/* my solution */
vector<Interval> merge(vector<Interval>& intervals) {
	vector<Interval> result = intervals;

	int curr = 0;
	for(int numOfCmp = result.size() - 1; numOfCmp > 0; numOfCmp--, curr++) {
		for(int i = curr + 1; i < numOfCmp; i++) {
			if(result.at(curr).end >= result.at(i).start) {
				int e = (result.at(i).end > result.at(curr).end) ? result.at(i).end : result.at(curr).end;
				int s = (result.at(i).start < result.at(curr).start) ? result.at(i).start : result.at(curr).start;
				Interval iv(s, e);

				result.erase(result.begin()+i);
				result[curr] = iv;
			}
		}
	}

	// test
	for(int i = 0; i < result.size(); i++) {
		cout << result[i].start << " " << result[i].end << endl;
	}

	return result;
}

/* 10-line solution */
vector<Interval> merge2(vector<Interval> &ins) {
	/* checks at first if ins is empty */
	//if(ins.empty()) return vector<Interval>{};
	vector<Interval> res;
	/* the use of sort (<algorithm>), 3rd arg is a function pointer */
	sort(ins.begin(), ins.end(), [](Interval a, Interval b) { return a.start < b.start; });
	res.push_back(ins[0]);
	/* the use of res.back() */
	for(int i = 1; i < ins.size(); i++) {
		if(res.back().end < ins[i].start) res.push_back(ins[i]);
		else res.back().end = max(res.back().end, ins[i].end);
	}
	return res;
}

int main() {
	Interval itv1(1, 3);
	Interval itv2(2, 6);
	Interval itv3(8, 10);
	Interval itv4(15, 18);
	vector<Interval> a;
	a.push_back(itv1);
	a.push_back(itv2);
	a.push_back(itv3);
	a.push_back(itv4);

	merge(a);

	return 0;
} 
