# OTP, Supervisors and Processes

**OTP** stands for *Open Telecom Platform*, and it's formed by three major interchangeble components:

1. Erlang;
2. Erlang  virtual machine libs;
3. Design principles.

Therefore the therm *OTP Compliant*, that means that the application follows Erlang/OTP systems design.

When refering to **processes** in Elixir, we are talking about Erlang's virtual machine processes, thus not your operating system processes. **BEAM** (Erlang virtual machine) processes are way more lightweight (~2k) bthan those forked and exec by your O.S., they run in every core available in your CPU, and also communicate with one another through **messages**, thus dividing the work load and running in parallel.

### Low Level OTP functions:
- *spawn*;
- *send*;
- *receive*.

### Abstract OTP functions:
- *Task*;
- *GenServer*;
- *Agent*.

