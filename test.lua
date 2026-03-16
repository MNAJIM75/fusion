client_init()

for i=1, 10 do
    client_send("Hello")
    local recv_msg = client_recv()
    if recv_msg then print(recv_msg) end
end

client_close()
