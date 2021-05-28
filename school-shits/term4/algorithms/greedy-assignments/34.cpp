/*
DFS Traverse
algortihm baraye sakhtane hame code ha ye dfs roye derakhte
tooye function call ye arg string mizarim ke reshte ta oon node
ro dashte bashe
har moghe be barg residim karemoon tamoom mishe

pseudo code

func dfs(node, code):
    if node is leave:
        save code for node.char
    else:
        for all adj of node:
            dfs(adj, code + direction(node))

    # where direction is 0 for left traverse and 1 otherwise
*/