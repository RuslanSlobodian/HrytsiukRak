#include "Tenant.h"
#include <iostream>

using namespace std;

Tenant::Tenant(const string& n, int aNo) : name(n), aptNumber(aNo) {}

Tenant::~Tenant() {}

int Tenant::getAptNumber() const {
    return aptNumber;
}

bool operator<(const Tenant& t1, const Tenant& t2) {
    return t1.name < t2.name;
}

bool operator==(const Tenant& t1, const Tenant& t2) {
    return t1.name == t2.name;
}

ostream& operator<<(ostream& s, const Tenant& t) {
    s << t.aptNumber << '\t' << t.name << endl;
    return s;
}

bool CompareTenants::operator()(const Tenant* ptrT1, const Tenant* ptrT2) const {
    return *ptrT1 < *ptrT2;
}
