from graphviz import Digraph

def draw_queue():
    dot = Digraph(comment='chain')
    dot.graph_attr['rankdir'] = 'LR'
    # Define node properties
    dot.node('front', 'a', shape='record', rank = "same")
    dot.node('rear', 'b', shape='record', rank = "same")
    dot.node("c", "c", shape = 'record', rank = "same")
    dot.node("d", "d", shape = 'record', rank = "same")
    # dot.node('empty', 'Empty', shape='record', style='filled', color='lightblue')
    dot.node("stack", shape="record", label="{ <tail> Address 7 | Address 6 | <data1> Address 5 | <data2> Address 4 | <data4> Address 3 |<data3> Address 2 | <head> Address 1 }", fontsize="10")

    dot.edge('stack:data2:s', 'rear', lhead='stack')
    # dot.edge('element1', 'element2', label='Next')
    # dot.edge('element2', 'element3', label='Next')
    dot.edge('stack:head:s', 'front', lhead='stack')

    dot.edge('front:e', 'c', lhead='stack')
    dot.edge('c:e', 'd', lhead='stack')

    # Save and render the graph
    dot.view()
    dot.render('chain', format='png', cleanup=True)

if __name__ == '__main__':
    draw_queue()

