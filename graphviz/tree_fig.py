from graphviz import Digraph

# 그래프 생성
dot = Digraph("Tree", engine='dot')

# 그래프 방향 설정 (TB: Top to Bottom)
dot.graph_attr['rankdir'] = 'TB'

dot.attr('node', shape='circle', width='0.6')

dot.node("1", shape="circle")
dot.node("2", shape="circle")
dot.node("3", shape="circle")
dot.node("4", shape="circle")
dot.node("5", shape="circle")





dot.edge("5", "4", dir='none', fontsize='10')
dot.edge("4", "3", dir='none', fontsize='10')
dot.edge("3", "2", dir='none', fontsize='10')
dot.edge("2", "1", dir='none', fontsize='10')


# 그래프 렌더링 및 저장
dot.render("bst", format="png", cleanup=True)
dot.view()