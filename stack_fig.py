from graphviz import Digraph

# 그래프 생성
dot = Digraph("Stack", engine='dot')

# 그래프 방향 설정 (TB: Top to Bottom)
dot.graph_attr['rankdir'] = 'TB'

# 스택 노드 및 연산 노드 추가
dot.node("stack", shape="record", label="{ <top> New Data 1 | <data> old Data  | <data> }", fontsize="10")
# dot.node("stack2", shape="record", label="{<f0> old Data }", fontsize="10")
# dot.node("push", "PUSH", fontsize="10", shape = "plaintext")
dot.node("top", "TOP", fontsize="10", shape = "plaintext")

# push 연산과 스택의 top을 연결
# dot.edge("push", "stack:top", arrowhead='vee', dir='forward', fontsize='10')
# dot.edge("stack:s", "stack2:n", label=" missing!", style="dashed", arrowhead="vee")

# pop 연산과 스택의 top을 연결
dot.edge("stack:top", "top", arrowhead='vee', dir='forward', fontsize='10')

# 그래프 렌더링 및 저장
dot.render("stack_graph", format="png", cleanup=True)
dot.view()
