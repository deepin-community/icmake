inline Args::Args(std::vector<SemVal> &semValVect)
:
    vector<SemVal>(std::move(semValVect))
{}
