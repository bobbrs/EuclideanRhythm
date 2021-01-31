#include "Euclidean.hpp"

string Euclidean::str() {
    string rhythm;
    for(bool g : _rhythm) {
        rhythm.append(g ? "1" : "0");
    }
    return rhythm;
}

void Euclidean::Generate(int steps, int pulses, int offset) {
    group rhythm;
    bool error = pulses <= 0 || pulses > steps || steps < 0 || offset < 0 || offset > steps;
   
    if (!error) {
        groups frontGroup(pulses, group(1, true));
        groups lastGroup(steps-pulses, group(1, false));

        groups rhythms = _Generate(frontGroup, lastGroup);

        for(group g : rhythms) {
            for(bool i : g) {
                rhythm.push_back(i);
            }
        }
    }

    rotate(rhythm.begin(), rhythm.begin()+rhythm.size()-offset, rhythm.end());
    
    _rhythm = rhythm;
}

groups Euclidean::_Generate(groups fgs, groups lgs) {
    if (lgs.size() < 2)
    {
        fgs.insert(fgs.end(), lgs.begin(), lgs.end());
    }
    else {
        groups nfgs;
        while (fgs.size() > 0 && lgs.size() > 0)
        {
            group flg = fgs.back();
            group llg = lgs.back();
            flg.insert(flg.end(), llg.begin(), llg.end());

            nfgs.push_back(flg);
            fgs.pop_back();
            lgs.pop_back();
        }
        fgs.insert(fgs.end(), lgs.begin(), lgs.end());
        return _Generate(nfgs, fgs);
    }
    return fgs;
}

group Euclidean::GetRhythm() {
    return _rhythm;
}
