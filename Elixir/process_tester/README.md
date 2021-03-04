# ProcessTester

Since Erlang is designed for massive concurrency, its processess are lighweighted, dynamically grown, with small memory footprint, fast to create and terminate and with low overhead schedulling.

To create a process we use the **spawn** function:

```elixir
spawn(Module, Name, Args) -> pid()
  Module = Name = atom()
  Args = [Arg1,...,ARgN]
    ArgI = term()
```

**spawn** creates a new process and returns the **pid** (Process ID).
