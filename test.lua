setmetatable(_G, {__index=rl})

InitWindow(800, 600, "Kate")
SetTargetFPS(60)

function client_task()
    client_init()
    while true do
        client_send("Hello")
        coroutine.yield()  -- pause here, resume later
        local recv_msg = client_recv()
        if recv_msg then
            print(recv_msg)
        end

    end
    client_close()
end

-- Create coroutine
co = coroutine.create(client_task)

local x, y = 10, 10
while not WindowShouldClose() and coroutine.status(co) ~= "dead" do
    -- update
    coroutine.resume(co)
    x = x + 10 * GetFrameTime()
    y = y + 10 * GetFrameTime()
    -- draw
    BeginDrawing()
    ClearBackground(WHITE)

    DrawFPS(10, 10)
    DrawCircle(x, y, 10, RED)

    EndDrawing()
end
if coroutine.status(co) ~= "dead" then client_close() end
CloseWindow()
