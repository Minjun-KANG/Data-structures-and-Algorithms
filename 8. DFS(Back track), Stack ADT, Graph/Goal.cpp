#include "Goal.h"

using namespace MyGoal;
/*
Algorithm seekGoal (map)
createStack(stack)
set pMap to starting point
loop (pMap not Null And goalNotFound)
	if (pMap is Goal)
		set goalNotFound
	else
		pushStack (stack, pMap)
		if(pMap is a branch point)
			loop (more branch point)
				Create branchpoint Node
				pushStack(stack, branchPoint)
			end loop
		end if
		advance to nextnode
	end if
end loop
if (emptyStack (stack))
	print (Theere is no path to your Goal)
else
	print (The path to your goal is : )
	loop (not EmptyStak (stack))
		popStack(stack, pMap)
		if(pMap not branchPoint)
			print(map point)
		end if
	end loop
	print(End of Path)
end if
return
end seekGoal
*/
int MyGoal::Goal::Goalseeking(GRAPH *m_graph, Stack *m_stack)
{
	
	//DATA cur_point;
	int goal_point = 0;
	bool goalNotFound = true;
	int cur_p = 0;
	//have parameter - m_stack  //createStack(stack)
	//starting point is zero	//set pMap to starting point
	cout << "set starting point : ";
	cin >> cur_p;
	cout << "set goal point : ";
	cin >> goal_point;
	//cur_p++;
	//goal_point--;
	if (cur_p > m_graph->n)
	{
		cout << "Total node exceeded. " << endl;
		return ERROR_INPUT;
	}
	G_NODE *root = m_graph->arr[cur_p].head;

	DATA temp_data;
	
	//start_point.main_data++;
	while (root != NULL && goalNotFound) //loop(pMap not Null And goalNotFound)
	{
		if (cur_p == goal_point) 	//if (pMap is Goal)
		{	//set goalNotFound to false
			cout << m_stack->list->front->data.main_data+1 << endl;
			cout << "goal" << endl;
			goalNotFound = false;
		}
		else //else
		{
			temp_data.main_data = cur_p;
			m_stack->Enstack(temp_data);//pushStack(stack, pMap)
			cout << m_stack->list->front->data.main_data << endl;
			if (cur_p == 1 || root->next == NULL) {
				if (cur_p == 1)
				{
					root = m_graph->arr[++cur_p].head;
					continue;
				}
				cout << "end point" << endl; // end point check
				root = m_graph->arr[++cur_p].head;
				continue;
			}
			if (root->next->next != NULL)	//if (pMap is a branch point) 브런치 노드가 존재할경우.
			{
				G_NODE *temp = root->next;
				while (temp != NULL)//loop(more branch point)
				{
					//predefined branchpoint //Create branchpoint Node
					//pushStack(stack, branchPoint)
					temp_data.main_data = temp->data;
					m_stack->Enstack(temp_data);
					//cout << m_stack->list->front->data.main_data << endl;
					cout << "Branch" << endl;
					temp = temp->next;
					if (temp->next == NULL)
						break;
				}//end loop

			}//end if
		}//end if
		//advance to nextnode
		root = m_graph->arr[++cur_p].head;
	}//end loop
	/*
	if (m_stack->IsEmpty())//if (emptyStack(stack)
	{
		//print(There is no path to your Goal)
		cout << "There is no path to your goal" << endl;
		return ERROR_EMPTY;
	}
	else
	{
		cout << "The path to your goal is : ";//print(The path to your goal is : )
		while (!m_stack->IsEmpty())	//loop(not EmptyStak(stack))
		{
			//popStack(stack, pMap)

			//cout << m_stack->StackFront()->data.main_data;
			m_stack->Destack(); //pop
			cout << m_stack->list->front->data.main_data << endl;

			if (root->next == NULL) //if (pMap not branchPoint)
			{
				//print(map point)
				cout << m_stack->StackFront()->data.main_data;
			}//end if
			
		}//end loop
		cout << "End of Path" << endl;//print(End of Path)
	}//end if
	*/
	return 0;
	//m_stack->all_printStack();
} //end seekGoal



Goal::Goal()
{
}


Goal::~Goal()
{
}