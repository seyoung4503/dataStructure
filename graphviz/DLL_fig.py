
from graphviz import Digraph

# 그래프 생성
dot = Digraph("Doubly Linked List", engine='dot')

dot.graph_attr['rankdir'] = 'LR'
# dot.graph_attr['nodesep'] = '0.1'

dot.node("nil1", "nil", shape = "circle", rank = "same")
dot.node("nil2", "nil", shape = "circle", rank = "same")

dot.node("nil3", "nil", shape = "circle", rank = "same")
dot.node("nil4", "nil", shape = "circle", rank = "same")
# dot.node("a", '<f0> prev|<f1> A  |<f2> next', fontsize='10', width='0.6', height='0.8', fixedsize='true', shape='record')


dot.node('node1', label='''<<table border="0" cellspacing="0" cellborder="1">
    <tr>
        <td port="ref1" width="28" height="36" fixedsize="true">prev</td>
        <td port="data" width="28" height="36" fixedsize="true">A</td>
        <td port="ref2" width="28" height="36" fixedsize="true">next</td>
    </tr>
</table>>''', fontsize='10', shape="plaintext", rank ="same")


dot.node('node2', label='''<<table border="0" cellspacing="0" cellborder="1">
    <tr>
        <td port="ref1" width="28" height="36" fixedsize="true">prev</td>
        <td port="data" width="28" height="36" fixedsize="true">B</td>
        <td port="ref2" width="28" height="36" fixedsize="true">next</td>
    </tr>
</table>>''', fontsize='10', shape="plaintext", rank ="same")

dot.node('node4', label='''<<table border="0" cellspacing="0" cellborder="1">
    <tr>
        <td port="ref1" width="28" height="36" fixedsize="true">prev</td>
        <td port="data" width="28" height="36" fixedsize="true">D</td>
        <td port="ref2" width="28" height="36" fixedsize="true">next</td>
    </tr>
</table>>''', fontsize='10', shape="plaintext", rank = "same")

dot.node('node3', label='''<<table border="0" cellspacing="0" cellborder="1">
    <tr>
        <td port="ref1" width="28" height="36" fixedsize="true">prev</td>
        <td port="data" width="28" height="36" fixedsize="true">C</td>
        <td port="ref2" width="28" height="36" fixedsize="true">next</td>
    </tr>
</table>>''', fontsize='10', shape="plaintext", rank ="same")



dot.edge("nil1", "node1:ref1", style="invis")
dot.edge('node1:ref2', 'node2:data:n', arrowhead="normal")
dot.edge('node2:ref1', 'node1:data:s', arrowhead="normal")
dot.edge("node1:ref1", "nil1", arrowtail="normal")
# dot.edge("node2:ref2", "nil2", arrowtail="normal")

# dot.edge("nil3", "node3:ref1", style="invis")
# dot.edge("node3:ref1", "nil3", arrowtail="normal")
dot.edge("node3:ref2", "nil4", arrowtail="normal")





# dot.edge("nil3", "node4:ref1", style="invis")
# dot.edge("node4:ref1", "nil3", arrowtail="normal", rank = "same")
# dot.edge("node4:ref2", "nil2", arrowtail="normal", rank = "same")

dot.edge( "node4:ref1", "node2:data:s", arrowtail="normal", rank = "same")
dot.edge( "node4:ref2", "node3:data:s", arrowtail="normal", rank = "same")
# dot.edge( "node2:ref2", "node3:data:n", arrowtail="normal", rank = "same")

dot.edge( "node3:ref1:w", "node2:data:s", label="1", fontsize="10", color="tomato", arrowtail="normal", rank = "same")
dot.edge( "node2:ref2", "node3:data:n", label="2", fontsize="10", color="tomato", arrowtail="normal", rank = "same")

dot.edge("node4:ref2", "nil2", arrowtail="normal")

dot.edge("nil3", "node:ref1", style="invis")
dot.edge("node3:ref1", "nil3", arrowtail="normal")
dot.render("node", format="png", cleanup=True)
dot.view()

# dot.edge("e", "node1:ref1:node2", arrowhead="dot", arrowtail="normal", dir="both", headclip="false")
# dot.edge("node1:ref2:node2", "node2:data:n", arrowhead="normal", arrowtail="dot", dir="both", tailclip="false")
# dot.edge("nil2", "node1:ref1:node2", arrowhead="dot", arrowtail="normal", dir="both", headclip="false")

# dot.edge("node1:ref2:node2", "node2:data:n", arrowhead="normal", arrowtail="dot", dir="both", tailclip="false", pos="e,10")

# # 연결 관계 설정
# dot.edge("e", "a:ref1:c", arrowhead="dot", arrowtail="normal", dir="both", headclip="false")
# dot.edge("a:ref2:c", "b:data:n", arrowhead="normal", arrowtail="dot", dir="both", tailclip="false")
# dot.edge("b:ref2:c", "c:data:n", arrowhead="normal", arrowtail="dot", dir="both", tailclip="false")
# dot.edge("c:ref2:c", "d:w", arrowhead="normal", arrowtail="dot", dir="both", tailclip="false")
# dot.edge("c:ref1:c", "b:data:s", arrowhead="normal", arrowtail="dot", dir="both", tailclip="false")
# dot.edge("b:ref1:c", "a:data:s", arrowhead="normal", arrowtail="dot", dir="both", tailclip="false")


# 그래프 시각화 및 이미지 저장



