defmodule Chat.Server do
  # GenServer = Generic Server
  use GenServer

  # CLIENT SIDE:
  def start_link do
    # "__MODULE__" is an atom that represents
    # Chat.Server.
    GenServer.start_link(__MODULE__, [], name: :chat_room)
  end

  def get_messages do
    GenServer.call(:chat_room, :get_messages)
  end

  def add_message(msg) do
    GenServer.cast(:chat_room, {:add_message, msg})
  end

  # SERVER SIDE/callback function:
  def init(msgs) do
    {:ok, msgs}
  end

  def handle_call(:get_messages, _from, msgs) do
    {:reply, msgs, msgs}
  end

  def handle_cast({:add_message, msg}, msgs) do
    {:noreply, [msg | msgs]}
  end

end
