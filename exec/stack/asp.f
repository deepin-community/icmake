inline void Stack::asp(uint16_t nElements)      // called from cpu/asp
{
    d_stack.resize(d_stack.size() - nElements);
}
