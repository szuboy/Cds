#include "stdio.h"
#include "SeqStack.h"

#include <string>
#include <vector>
#include <iostream>


bool get_opt_priority(std::string c1, std::string c2, std::string priority)     
{
	int i = 0, j = 0;
	static std::string opt_array[49] = {
	">", ">", "<", "<", "<", ">", ">",
	">", ">", "<", "<", "<", ">", ">",
	">", ">", ">", ">", "<", ">", ">",
	">", ">", ">", ">", "<", ">", ">",
	"<", "<", "<", "<", "<", "=", "!",
	">", ">", ">", ">", "!", ">", ">",
	"<", "<", "<", "<", "<", "!", "=" };

	if (c1 == "+")
		i = 0;
	else if (c1 == "-")
		i = 1;
	else if (c1 == "*")
		i = 2;
	else if (c1 == "/")
		i = 3;
	else if (c1 == "(")
		i = 4;
	else if (c1 == ")")
		i = 5;
	else if (c1 == "#")
		i = 6;

	if (c2 == "+")
		j = 0;
	else if (c2 == "-")
		j = 1;
	else if (c2 == "*")
		j = 2;
	else if (c2 == "/")
		j = 3;
	else if (c2 == "(")
		j = 4;
	else if (c2 == ")")
		j = 5;
	else if (c2 == "#")
		j = 6;

	priority = opt_array[7 * i + j];

	return true;
}


bool cal_expression_base_opt(std::string opt, SeqStack &node_stack)
{
	std::string a, b;
	pop_seqstack_node(node_stack, a), pop_seqstack_node(node_stack, b);
	if (opt == "+")
		push_seqstack_node(node_stack, std::to_string(atof(a.c_str()) + atof(b.c_str())));
	if (opt == "-")
		push_seqstack_node(node_stack, std::to_string(atof(a.c_str()) - atof(b.c_str())));
	if (opt == "*")
		push_seqstack_node(node_stack, std::to_string(atof(a.c_str()) * atof(b.c_str())));
	if (opt == "/")
		push_seqstack_node(node_stack, std::to_string(atof(a.c_str()) / atof(b.c_str())));
	return true;
}


bool split_expression_base_opt(std::string expression, std::vector<std::string> &list)
{
	int i = 0, j = 0;
	std::string node;

	for (i = 0; i < expression.size();) {
		if (expression[i] == '(' || expression[i] == ')' || expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
			node = expression[i], i++;
		else {
			for (j = i + 1; j < expression.size(); j++)
				if (!isdigit(expression[j]) && expression[j] != '.')  break;
			node = expression.substr(i, j - i), i = j;
		}
		list.push_back(node);
	}
	return true;
}


bool evaluate_expression_base_stack(std::string expression, float &ret_value)
{
	std::vector<std::string> express_split_list;
	split_expression_base_opt(expression, express_split_list);

	std::string opts;
	SeqStack node_stack, opts_stack;
	if (!init_seq_stack(node_stack) || !init_seq_stack(opts_stack))
		return false;

	for (long int i = 0; i < express_split_list.size(); i++) {
		if (express_split_list[i] == "(")
			push_seqstack_node(opts_stack, "(");

		else if (express_split_list[i] == ")")
			while (get_seqstack_length(opts_stack)) {
				pop_seqstack_node(opts_stack, opts);
				if (opts == "(")
					break;
				cal_expression_base_opt(opts, node_stack);
			}

		else if (express_split_list[i] == "+" || express_split_list[i] == "-") {
			if (get_seqstack_length(opts_stack)) {
				pop_seqstack_node(opts_stack, opts);
				if (opts == "(")
					push_seqstack_node(opts_stack, opts);
				else
					cal_expression_base_opt(opts, node_stack);
			}
			push_seqstack_node(opts_stack, express_split_list[i]);
		}

		else if (express_split_list[i] == "/" || express_split_list[i] == "*") {
			if (get_seqstack_length(opts_stack)) {
				pop_seqstack_node(opts_stack, opts);
				if (opts == "(" || opts == "+" || opts == "-")
					push_seqstack_node(opts_stack, opts);
				if (opts == "*" || opts == "/")
					cal_expression_base_opt(opts, node_stack);
			}
			push_seqstack_node(opts_stack, express_split_list[i]);
		}

		else
			push_seqstack_node(node_stack, express_split_list[i]);
	}

	while (get_seqstack_length(opts_stack)) {
		pop_seqstack_node(opts_stack, opts);
		cal_expression_base_opt(opts, node_stack);
	}
	
	pop_seqstack_node(node_stack, opts);
	ret_value = atof(opts.c_str());
	return true;
}


int main()
{
	
	std::string expression = "2*(1+4)+2.5*4-10";
	std::cout << ">>>" << expression << std::endl;
	
	
	std::vector<std::string> express_split_list;
	split_expression_base_opt(expression, express_split_list);
	for (int i = 0; i < express_split_list.size(); i++)
		std::cout << express_split_list[i] << " ";
	std::cout << std::endl << std::endl;
	
	/*
	float ret_value;
	evaluate_expression_base_stack(expression, ret_value);
	std::cout << ret_value << std::endl;
	*/
	/*
	SeqStack num_stack;
	if (!init_seq_stack(num_stack))
		return 0;

	for (int i = 0; i < 10; i++) {
		push_seqstack_node(num_stack, i);
	}

	int node;
	while (!is_seqstack_empty(num_stack)) {
		pop_seqstack_node(num_stack, node);
		printf("%d ", node);
	}
	printf("\n");
	*/
	return 0;
}

