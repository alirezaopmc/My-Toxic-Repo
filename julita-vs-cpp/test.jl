@time begin
    xyz = 0
    for i in 0:99999
        global xyz += 1
    end
    println(xyz)
end