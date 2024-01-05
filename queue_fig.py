from graphviz import Digraph

def draw_queue():
    dot = Digraph(comment='Queue')
    dot.graph_attr['rankdir'] = 'LR'
    # Define node properties
    dot.node('front', 'Front', shape='circle')
    dot.node('rear', 'Rear', shape='circle')
    # dot.node('empty', 'Empty', shape='record', style='filled', color='lightblue')
    dot.node("stack", shape="record", label="{ <tail> · | · | <data1> · | <data2> · | <data4> Element 4 |<data3> Element 3 | <head> Element 2 }", fontsize="10")

    # dot.node('element1', 'Element 1', shape='record')
    # dot.node('element2', 'Element 2', shape='record')
    # dot.node('element3', 'Element 3', shape='record')

    # Define edge properties
    # dot.edge('empty', 'front')
    # dot.edge('empty', 'rear')
    dot.edge('rear', 'stack:data2', label='enQueue()')
    # dot.edge('element1', 'element2', label='Next')
    # dot.edge('element2', 'element3', label='Next')
    dot.edge('stack:head', 'front', label='deQueue()')

    # Save and render the graph
    dot.view()
    dot.render('queue_graph', format='png', cleanup=True)

if __name__ == '__main__':
    draw_queue()

