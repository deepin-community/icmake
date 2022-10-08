inline Args::Args(SemVal &semVal)
:
    vector<SemVal>(1, std::move(semVal))
{}
