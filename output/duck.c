/* auto-generated compiler stubs */
#include "lr_parser.h"
#include "duck.h"


/* production stubs */

/* 1. <program> -> <top-level-block> */
int ReduceProgram(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* top_level_block1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(top_level_block1));

    return error;
}

/* 2. <top-level-block> -> <top-level-stmt> <top-level-block> */
int ReduceTopLevelBlockA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* top_level_stmt1 = node->children[0];
    SYNTAX_TREE* top_level_block1 = node->children[1];

    int error = 0;
    error = (error ? error : ProcessNode(top_level_stmt1));
    error = (error ? error : ProcessNode(top_level_block1));

    return error;
}

/* 3. <top-level-block> -> */
int ReduceTopLevelBlockB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 0);

    int error = 0;

    return error;
}

/* 4. <identifier-list> -> <identifier> , <identifier-list> */
int ReduceIdentifierListA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* identifier1 = node->children[0];
    SYNTAX_TREE* identifier_list1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(identifier1));
    error = (error ? error : ProcessNode(identifier_list1));

    return error;
}

/* 5. <identifier-list> -> <identifier> */
int ReduceIdentifierListB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* identifier1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(identifier1));

    return error;
}

/* 6. <optendl> -> <endl> */
int ReduceOptendlA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);

    int error = 0;

    return error;
}

/* 7. <optendl> -> */
int ReduceOptendlB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 0);

    int error = 0;

    return error;
}

/* 8. <top-level-stmt> -> import <identifier-list> <endl> */
int ReduceTopLevelStmtA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* identifier_list1 = node->children[1];

    int error = 0;
    error = (error ? error : ProcessNode(identifier_list1));

    return error;
}

/* 9. <top-level-stmt> -> include <string> <endl> */
int ReduceTopLevelStmtB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* string1 = node->children[1];

    int error = 0;
    error = (error ? error : ProcessNode(string1));

    return error;
}

/* 10. <top-level-stmt> -> module <identifier> <endl> <block> endmodule <endl> */
int ReduceTopLevelStmtC(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 6);
    SYNTAX_TREE* identifier1 = node->children[1];
    SYNTAX_TREE* block1 = node->children[3];

    int error = 0;
    error = (error ? error : ProcessNode(identifier1));
    error = (error ? error : ProcessNode(block1));

    return error;
}

/* 11. <top-level-stmt> -> <stmt> */
int ReduceTopLevelStmtD(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* stmt1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(stmt1));

    return error;
}

/* 12. <block> -> <stmt> <block> */
int ReduceBlockA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* stmt1 = node->children[0];
    SYNTAX_TREE* block1 = node->children[1];

    int error = 0;
    error = (error ? error : ProcessNode(stmt1));
    error = (error ? error : ProcessNode(block1));

    return error;
}

/* 13. <block> -> */
int ReduceBlockB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 0);

    int error = 0;

    return error;
}

/* 14. <stmt> -> <expr> <endl> */
int ReduceStmtA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* expr1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(expr1));

    return error;
}

/* 15. <stmt> -> <assignment> <endl> */
int ReduceStmtB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* assignment1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(assignment1));

    return error;
}

/* 16. <stmt> -> <self-assignment> <endl> */
int ReduceStmtC(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* self_assignment1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(self_assignment1));

    return error;
}

/* 17. <stmt> -> <class> <endl> */
int ReduceStmtD(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* class1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(class1));

    return error;
}

/* 18. <stmt> -> <function> <endl> */
int ReduceStmtE(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* function1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(function1));

    return error;
}

/* 19. <stmt> -> <if> <endl> */
int ReduceStmtF(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* if1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(if1));

    return error;
}

/* 20. <stmt> -> <for> <endl> */
int ReduceStmtG(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* for1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(for1));

    return error;
}

/* 21. <stmt> -> <while> <endl> */
int ReduceStmtH(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* while1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(while1));

    return error;
}

/* 22. <stmt> -> <let-block> <endl> */
int ReduceStmtI(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* let_block1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(let_block1));

    return error;
}

/* 23. <stmt> -> <try-block> <endl> */
int ReduceStmtJ(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* try_block1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(try_block1));

    return error;
}

/* 24. <stmt> -> return <endl> */
int ReduceStmtK(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);

    int error = 0;

    return error;
}

/* 25. <stmt> -> return <expr> <endl> */
int ReduceStmtL(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* expr1 = node->children[1];

    int error = 0;
    error = (error ? error : ProcessNode(expr1));

    return error;
}

/* 26. <stmt> -> continue <endl> */
int ReduceStmtM(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);

    int error = 0;

    return error;
}

/* 27. <stmt> -> break <endl> */
int ReduceStmtN(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);

    int error = 0;

    return error;
}

/* 28. <stmt> -> throw <expr> <endl> */
int ReduceStmtO(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* expr1 = node->children[1];

    int error = 0;
    error = (error ? error : ProcessNode(expr1));

    return error;
}

/* 29. <stmt> -> <endl> */
int ReduceStmtP(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);

    int error = 0;

    return error;
}

/* 30. <class> -> class <identifier> <parameters> <class-ext> */
int ReduceClass(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 4);
    SYNTAX_TREE* identifier1 = node->children[1];
    SYNTAX_TREE* parameters1 = node->children[2];
    SYNTAX_TREE* class_ext1 = node->children[3];

    int error = 0;
    error = (error ? error : ProcessNode(identifier1));
    error = (error ? error : ProcessNode(parameters1));
    error = (error ? error : ProcessNode(class_ext1));

    return error;
}

/* 31. <class-ext> -> extends <identifier-list> <endl> <class-body> */
int ReduceClassExtA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 4);
    SYNTAX_TREE* identifier_list1 = node->children[1];
    SYNTAX_TREE* class_body1 = node->children[3];

    int error = 0;
    error = (error ? error : ProcessNode(identifier_list1));
    error = (error ? error : ProcessNode(class_body1));

    return error;
}

/* 32. <class-ext> -> <endl> <class-body> */
int ReduceClassExtB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* class_body1 = node->children[1];

    int error = 0;
    error = (error ? error : ProcessNode(class_body1));

    return error;
}

/* 33. <class-body> -> <block> endclass */
int ReduceClassBody(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* block1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(block1));

    return error;
}

/* 34. <function> -> func <identifier> <function-def> */
int ReduceFunctionA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* identifier1 = node->children[1];
    SYNTAX_TREE* function_def1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(identifier1));
    error = (error ? error : ProcessNode(function_def1));

    return error;
}

/* 35. <function> -> func <string> <function-def> */
int ReduceFunctionB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* string1 = node->children[1];
    SYNTAX_TREE* function_def1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(string1));
    error = (error ? error : ProcessNode(function_def1));

    return error;
}

/* 36. <function-def> -> <parameters> <endl> <block> endfunc */
int ReduceFunctionDef(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 4);
    SYNTAX_TREE* parameters1 = node->children[0];
    SYNTAX_TREE* block1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(parameters1));
    error = (error ? error : ProcessNode(block1));

    return error;
}

/* 37. <parameters> -> ( <identifier-list> ) */
int ReduceParametersA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* identifier_list1 = node->children[1];

    int error = 0;
    error = (error ? error : ProcessNode(identifier_list1));

    return error;
}

/* 38. <parameters> -> ( ) */
int ReduceParametersB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);

    int error = 0;

    return error;
}

/* 39. <parameters> -> */
int ReduceParametersC(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 0);

    int error = 0;

    return error;
}

/* 40. <arguments> -> */
int ReduceArgumentsA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 0);

    int error = 0;

    return error;
}

/* 41. <arguments> -> <expr-list> */
int ReduceArgumentsB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* expr_list1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(expr_list1));

    return error;
}

/* 42. <expr-list> -> <expr> , <expr-list> */
int ReduceExprListA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* expr1 = node->children[0];
    SYNTAX_TREE* expr_list1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(expr1));
    error = (error ? error : ProcessNode(expr_list1));

    return error;
}

/* 43. <expr-list> -> <expr> */
int ReduceExprListB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* expr1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(expr1));

    return error;
}

/* 44. <if> -> if <condition> then <endl> <block> <elseif> */
int ReduceIf(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 6);
    SYNTAX_TREE* condition1 = node->children[1];
    SYNTAX_TREE* block1 = node->children[4];
    SYNTAX_TREE* elseif1 = node->children[5];

    int error = 0;
    error = (error ? error : ProcessNode(condition1));
    error = (error ? error : ProcessNode(block1));
    error = (error ? error : ProcessNode(elseif1));

    return error;
}

/* 45. <elseif> -> else <endl> <block> endif */
int ReduceElseifA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 4);
    SYNTAX_TREE* block1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(block1));

    return error;
}

/* 46. <elseif> -> else <if> */
int ReduceElseifB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* if1 = node->children[1];

    int error = 0;
    error = (error ? error : ProcessNode(if1));

    return error;
}

/* 47. <elseif> -> endif */
int ReduceElseifC(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);

    int error = 0;

    return error;
}

/* 48. <for> -> for <identifier> <for-start> */
int ReduceFor(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* identifier1 = node->children[1];
    SYNTAX_TREE* for_start1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(identifier1));
    error = (error ? error : ProcessNode(for_start1));

    return error;
}

/* 49. <for-start> -> = <arithmetic> to <arithmetic> do <endl> <loop-end> */
int ReduceForStartA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 7);
    SYNTAX_TREE* arithmetic1 = node->children[1];
    SYNTAX_TREE* arithmetic2 = node->children[3];
    SYNTAX_TREE* loop_end1 = node->children[6];

    int error = 0;
    error = (error ? error : ProcessNode(arithmetic1));
    error = (error ? error : ProcessNode(arithmetic2));
    error = (error ? error : ProcessNode(loop_end1));

    return error;
}

/* 50. <for-start> -> = <arithmetic> to <arithmetic> step <arithmetic> do <endl> <loop-end> */
int ReduceForStartB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 9);
    SYNTAX_TREE* arithmetic1 = node->children[1];
    SYNTAX_TREE* arithmetic2 = node->children[3];
    SYNTAX_TREE* arithmetic3 = node->children[5];
    SYNTAX_TREE* loop_end1 = node->children[8];

    int error = 0;
    error = (error ? error : ProcessNode(arithmetic1));
    error = (error ? error : ProcessNode(arithmetic2));
    error = (error ? error : ProcessNode(arithmetic3));
    error = (error ? error : ProcessNode(loop_end1));

    return error;
}

/* 51. <for-start> -> in <value> do <endl> <loop-end> */
int ReduceForStartC(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 5);
    SYNTAX_TREE* value1 = node->children[1];
    SYNTAX_TREE* loop_end1 = node->children[4];

    int error = 0;
    error = (error ? error : ProcessNode(value1));
    error = (error ? error : ProcessNode(loop_end1));

    return error;
}

/* 52. <for-start> -> , <identifier> in <value> do <endl> <loop-end> */
int ReduceForStartD(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 7);
    SYNTAX_TREE* identifier1 = node->children[1];
    SYNTAX_TREE* value1 = node->children[3];
    SYNTAX_TREE* loop_end1 = node->children[6];

    int error = 0;
    error = (error ? error : ProcessNode(identifier1));
    error = (error ? error : ProcessNode(value1));
    error = (error ? error : ProcessNode(loop_end1));

    return error;
}

/* 53. <while> -> while <condition> do <endl> <loop-end> */
int ReduceWhileA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 5);
    SYNTAX_TREE* condition1 = node->children[1];
    SYNTAX_TREE* loop_end1 = node->children[4];

    int error = 0;
    error = (error ? error : ProcessNode(condition1));
    error = (error ? error : ProcessNode(loop_end1));

    return error;
}

/* 54. <while> -> do <endl> <block> loop while <condition> */
int ReduceWhileB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 6);
    SYNTAX_TREE* block1 = node->children[2];
    SYNTAX_TREE* condition1 = node->children[5];

    int error = 0;
    error = (error ? error : ProcessNode(block1));
    error = (error ? error : ProcessNode(condition1));

    return error;
}

/* 55. <loop-end> -> <block> loop */
int ReduceLoopEnd(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* block1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(block1));

    return error;
}

/* 56. <let-block> -> let <bindings> <endl> begin <endl> <block> end */
int ReduceLetBlock(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 7);
    SYNTAX_TREE* bindings1 = node->children[1];
    SYNTAX_TREE* block1 = node->children[5];

    int error = 0;
    error = (error ? error : ProcessNode(bindings1));
    error = (error ? error : ProcessNode(block1));

    return error;
}

/* 57. <bindings> -> <binding> , <optendl> <bindings> */
int ReduceBindingsA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 4);
    SYNTAX_TREE* binding1 = node->children[0];
    SYNTAX_TREE* optendl1 = node->children[2];
    SYNTAX_TREE* bindings1 = node->children[3];

    int error = 0;
    error = (error ? error : ProcessNode(binding1));
    error = (error ? error : ProcessNode(optendl1));
    error = (error ? error : ProcessNode(bindings1));

    return error;
}

/* 58. <bindings> -> <binding> */
int ReduceBindingsB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* binding1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(binding1));

    return error;
}

/* 59. <binding> -> <identifier> = <expr> */
int ReduceBinding(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* identifier1 = node->children[0];
    SYNTAX_TREE* expr1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(identifier1));
    error = (error ? error : ProcessNode(expr1));

    return error;
}

/* 60. <try-block> -> try <endl> <block> <catch-block> */
int ReduceTryBlock(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 4);
    SYNTAX_TREE* block1 = node->children[2];
    SYNTAX_TREE* catch_block1 = node->children[3];

    int error = 0;
    error = (error ? error : ProcessNode(block1));
    error = (error ? error : ProcessNode(catch_block1));

    return error;
}

/* 61. <catch-block> -> catch <l-value> <endl> <block> done */
int ReduceCatchBlockA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 5);
    SYNTAX_TREE* l_value1 = node->children[1];
    SYNTAX_TREE* block1 = node->children[3];

    int error = 0;
    error = (error ? error : ProcessNode(l_value1));
    error = (error ? error : ProcessNode(block1));

    return error;
}

/* 62. <catch-block> -> done */
int ReduceCatchBlockB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);

    int error = 0;

    return error;
}

/* 63. <assignment> -> <l-value> = <expr> */
int ReduceAssignmentA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* l_value1 = node->children[0];
    SYNTAX_TREE* expr1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(l_value1));
    error = (error ? error : ProcessNode(expr1));

    return error;
}

/* 64. <assignment> -> <l-value> = <object> */
int ReduceAssignmentB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* l_value1 = node->children[0];
    SYNTAX_TREE* object1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(l_value1));
    error = (error ? error : ProcessNode(object1));

    return error;
}

/* 65. <self-assignment> -> <l-value> += <arithmetic> */
int ReduceSelfAssignmentA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* l_value1 = node->children[0];
    SYNTAX_TREE* arithmetic1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(l_value1));
    error = (error ? error : ProcessNode(arithmetic1));

    return error;
}

/* 66. <self-assignment> -> <l-value> -= <arithmetic> */
int ReduceSelfAssignmentB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* l_value1 = node->children[0];
    SYNTAX_TREE* arithmetic1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(l_value1));
    error = (error ? error : ProcessNode(arithmetic1));

    return error;
}

/* 67. <self-assignment> -> <l-value> *= <arithmetic> */
int ReduceSelfAssignmentC(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* l_value1 = node->children[0];
    SYNTAX_TREE* arithmetic1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(l_value1));
    error = (error ? error : ProcessNode(arithmetic1));

    return error;
}

/* 68. <self-assignment> -> <l-value> /= <arithmetic> */
int ReduceSelfAssignmentD(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* l_value1 = node->children[0];
    SYNTAX_TREE* arithmetic1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(l_value1));
    error = (error ? error : ProcessNode(arithmetic1));

    return error;
}

/* 69. <self-assignment> -> <l-value> ++ */
int ReduceSelfAssignmentE(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* l_value1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(l_value1));

    return error;
}

/* 70. <self-assignment> -> <l-value> -- */
int ReduceSelfAssignmentF(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* l_value1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(l_value1));

    return error;
}

/* 71. <l-value> -> <identifier> */
int ReduceLValueA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* identifier1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(identifier1));

    return error;
}

/* 72. <l-value> -> <l-value> [ <arithmetic> ] */
int ReduceLValueB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 4);
    SYNTAX_TREE* l_value1 = node->children[0];
    SYNTAX_TREE* arithmetic1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(l_value1));
    error = (error ? error : ProcessNode(arithmetic1));

    return error;
}

/* 73. <l-value> -> <l-value> . <identifier> */
int ReduceLValueC(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* l_value1 = node->children[0];
    SYNTAX_TREE* identifier1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(l_value1));
    error = (error ? error : ProcessNode(identifier1));

    return error;
}

/* 74. <expr> -> <condition> */
int ReduceExpr(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* condition1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(condition1));

    return error;
}

/* 75. <condition> -> <condition> and <logic> */
int ReduceConditionA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* condition1 = node->children[0];
    SYNTAX_TREE* logic1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(condition1));
    error = (error ? error : ProcessNode(logic1));

    return error;
}

/* 76. <condition> -> <condition> or <logic> */
int ReduceConditionB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* condition1 = node->children[0];
    SYNTAX_TREE* logic1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(condition1));
    error = (error ? error : ProcessNode(logic1));

    return error;
}

/* 77. <condition> -> <logic> */
int ReduceConditionC(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* logic1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(logic1));

    return error;
}

/* 78. <logic> -> not <comparison> */
int ReduceLogicA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* comparison1 = node->children[1];

    int error = 0;
    error = (error ? error : ProcessNode(comparison1));

    return error;
}

/* 79. <logic> -> <comparison> */
int ReduceLogicB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* comparison1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(comparison1));

    return error;
}

/* 80. <comparison> -> <comparison> == <arithmetic> */
int ReduceComparisonA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* comparison1 = node->children[0];
    SYNTAX_TREE* arithmetic1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(comparison1));
    error = (error ? error : ProcessNode(arithmetic1));

    return error;
}

/* 81. <comparison> -> <comparison> != <arithmetic> */
int ReduceComparisonB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* comparison1 = node->children[0];
    SYNTAX_TREE* arithmetic1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(comparison1));
    error = (error ? error : ProcessNode(arithmetic1));

    return error;
}

/* 82. <comparison> -> <comparison> < <arithmetic> */
int ReduceComparisonC(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* comparison1 = node->children[0];
    SYNTAX_TREE* arithmetic1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(comparison1));
    error = (error ? error : ProcessNode(arithmetic1));

    return error;
}

/* 83. <comparison> -> <comparison> > <arithmetic> */
int ReduceComparisonD(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* comparison1 = node->children[0];
    SYNTAX_TREE* arithmetic1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(comparison1));
    error = (error ? error : ProcessNode(arithmetic1));

    return error;
}

/* 84. <comparison> -> <comparison> <= <arithmetic> */
int ReduceComparisonE(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* comparison1 = node->children[0];
    SYNTAX_TREE* arithmetic1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(comparison1));
    error = (error ? error : ProcessNode(arithmetic1));

    return error;
}

/* 85. <comparison> -> <comparison> >= <arithmetic> */
int ReduceComparisonF(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* comparison1 = node->children[0];
    SYNTAX_TREE* arithmetic1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(comparison1));
    error = (error ? error : ProcessNode(arithmetic1));

    return error;
}

/* 86. <comparison> -> <value> is <l-value> */
int ReduceComparisonG(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* value1 = node->children[0];
    SYNTAX_TREE* l_value1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(value1));
    error = (error ? error : ProcessNode(l_value1));

    return error;
}

/* 87. <comparison> -> <value> is not <l-value> */
int ReduceComparisonH(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 4);
    SYNTAX_TREE* value1 = node->children[0];
    SYNTAX_TREE* l_value1 = node->children[3];

    int error = 0;
    error = (error ? error : ProcessNode(value1));
    error = (error ? error : ProcessNode(l_value1));

    return error;
}

/* 88. <comparison> -> <arithmetic> */
int ReduceComparisonI(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* arithmetic1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(arithmetic1));

    return error;
}

/* 89. <arithmetic> -> <arithmetic> + <term> */
int ReduceArithmeticA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* arithmetic1 = node->children[0];
    SYNTAX_TREE* term1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(arithmetic1));
    error = (error ? error : ProcessNode(term1));

    return error;
}

/* 90. <arithmetic> -> <arithmetic> - <term> */
int ReduceArithmeticB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* arithmetic1 = node->children[0];
    SYNTAX_TREE* term1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(arithmetic1));
    error = (error ? error : ProcessNode(term1));

    return error;
}

/* 91. <arithmetic> -> <term> */
int ReduceArithmeticC(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* term1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(term1));

    return error;
}

/* 92. <term> -> <term> * <factor> */
int ReduceTermA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* term1 = node->children[0];
    SYNTAX_TREE* factor1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(term1));
    error = (error ? error : ProcessNode(factor1));

    return error;
}

/* 93. <term> -> <term> / <factor> */
int ReduceTermB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* term1 = node->children[0];
    SYNTAX_TREE* factor1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(term1));
    error = (error ? error : ProcessNode(factor1));

    return error;
}

/* 94. <term> -> <term> mod <factor> */
int ReduceTermC(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* term1 = node->children[0];
    SYNTAX_TREE* factor1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(term1));
    error = (error ? error : ProcessNode(factor1));

    return error;
}

/* 95. <term> -> <factor> */
int ReduceTermD(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* factor1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(factor1));

    return error;
}

/* 96. <factor> -> - <value> */
int ReduceFactorA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* value1 = node->children[1];

    int error = 0;
    error = (error ? error : ProcessNode(value1));

    return error;
}

/* 97. <factor> -> ! <value> */
int ReduceFactorB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* value1 = node->children[1];

    int error = 0;
    error = (error ? error : ProcessNode(value1));

    return error;
}

/* 98. <factor> -> <value> */
int ReduceFactorC(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* value1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(value1));

    return error;
}

/* 99. <value> -> <primitive> */
int ReduceValueA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* primitive1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(primitive1));

    return error;
}

/* 100. <value> -> <l-value> */
int ReduceValueB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* l_value1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(l_value1));

    return error;
}

/* 101. <value> -> <l-value> ( <arguments> ) */
int ReduceValueC(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 4);
    SYNTAX_TREE* l_value1 = node->children[0];
    SYNTAX_TREE* arguments1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(l_value1));
    error = (error ? error : ProcessNode(arguments1));

    return error;
}

/* 102. <value> -> ( <expr> ) */
int ReduceValueD(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* expr1 = node->children[1];

    int error = 0;
    error = (error ? error : ProcessNode(expr1));

    return error;
}

/* 103. <primitive> -> true */
int ReducePrimitiveA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);

    int error = 0;

    return error;
}

/* 104. <primitive> -> false */
int ReducePrimitiveB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);

    int error = 0;

    return error;
}

/* 105. <primitive> -> <integer> */
int ReducePrimitiveC(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* integer1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(integer1));

    return error;
}

/* 106. <primitive> -> <float> */
int ReducePrimitiveD(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* float1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(float1));

    return error;
}

/* 107. <primitive> -> <string> */
int ReducePrimitiveE(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* string1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(string1));

    return error;
}

/* 108. <object> -> [ <optendl> ] */
int ReduceObjectA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* optendl1 = node->children[1];

    int error = 0;
    error = (error ? error : ProcessNode(optendl1));

    return error;
}

/* 109. <object> -> [ <optendl> <array-init> */
int ReduceObjectB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* optendl1 = node->children[1];
    SYNTAX_TREE* array_init1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(optendl1));
    error = (error ? error : ProcessNode(array_init1));

    return error;
}

/* 110. <object> -> [ <optendl> <dictionary-init> */
int ReduceObjectC(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* optendl1 = node->children[1];
    SYNTAX_TREE* dictionary_init1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(optendl1));
    error = (error ? error : ProcessNode(dictionary_init1));

    return error;
}

/* 111. <array-init> -> <expr> , <optendl> <array-init> */
int ReduceArrayInitA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 4);
    SYNTAX_TREE* expr1 = node->children[0];
    SYNTAX_TREE* optendl1 = node->children[2];
    SYNTAX_TREE* array_init1 = node->children[3];

    int error = 0;
    error = (error ? error : ProcessNode(expr1));
    error = (error ? error : ProcessNode(optendl1));
    error = (error ? error : ProcessNode(array_init1));

    return error;
}

/* 112. <array-init> -> <expr> <optendl> ] */
int ReduceArrayInitB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* expr1 = node->children[0];
    SYNTAX_TREE* optendl1 = node->children[1];

    int error = 0;
    error = (error ? error : ProcessNode(expr1));
    error = (error ? error : ProcessNode(optendl1));

    return error;
}

/* 113. <dictionary-init> -> <dictionary-entry> , <optendl> <dictionary-init> */
int ReduceDictionaryInitA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 4);
    SYNTAX_TREE* dictionary_entry1 = node->children[0];
    SYNTAX_TREE* optendl1 = node->children[2];
    SYNTAX_TREE* dictionary_init1 = node->children[3];

    int error = 0;
    error = (error ? error : ProcessNode(dictionary_entry1));
    error = (error ? error : ProcessNode(optendl1));
    error = (error ? error : ProcessNode(dictionary_init1));

    return error;
}

/* 114. <dictionary-init> -> <dictionary-entry> ] */
int ReduceDictionaryInitB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* dictionary_entry1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(dictionary_entry1));

    return error;
}

/* 115. <dictionary-entry> -> <identifier> : <optendl> <expr> */
int ReduceDictionaryEntry(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 4);
    SYNTAX_TREE* identifier1 = node->children[0];
    SYNTAX_TREE* optendl1 = node->children[2];
    SYNTAX_TREE* expr1 = node->children[3];

    int error = 0;
    error = (error ? error : ProcessNode(identifier1));
    error = (error ? error : ProcessNode(optendl1));
    error = (error ? error : ProcessNode(expr1));

    return error;
}

/* reduce one node */
int ProcessNode(SYNTAX_TREE* node)
{
    if (node == NULL || node->production == 0)
        return 1;

    switch (node->production)
    {
        case 0x01: return ReduceProgram(node);
        case 0x02: return ReduceTopLevelBlockA(node);
        case 0x03: return ReduceTopLevelBlockB(node);
        case 0x04: return ReduceIdentifierListA(node);
        case 0x05: return ReduceIdentifierListB(node);
        case 0x06: return ReduceOptendlA(node);
        case 0x07: return ReduceOptendlB(node);
        case 0x08: return ReduceTopLevelStmtA(node);
        case 0x09: return ReduceTopLevelStmtB(node);
        case 0x0A: return ReduceTopLevelStmtC(node);
        case 0x0B: return ReduceTopLevelStmtD(node);
        case 0x0C: return ReduceBlockA(node);
        case 0x0D: return ReduceBlockB(node);
        case 0x0E: return ReduceStmtA(node);
        case 0x0F: return ReduceStmtB(node);
        case 0x10: return ReduceStmtC(node);
        case 0x11: return ReduceStmtD(node);
        case 0x12: return ReduceStmtE(node);
        case 0x13: return ReduceStmtF(node);
        case 0x14: return ReduceStmtG(node);
        case 0x15: return ReduceStmtH(node);
        case 0x16: return ReduceStmtI(node);
        case 0x17: return ReduceStmtJ(node);
        case 0x18: return ReduceStmtK(node);
        case 0x19: return ReduceStmtL(node);
        case 0x1A: return ReduceStmtM(node);
        case 0x1B: return ReduceStmtN(node);
        case 0x1C: return ReduceStmtO(node);
        case 0x1D: return ReduceStmtP(node);
        case 0x1E: return ReduceClass(node);
        case 0x1F: return ReduceClassExtA(node);
        case 0x20: return ReduceClassExtB(node);
        case 0x21: return ReduceClassBody(node);
        case 0x22: return ReduceFunctionA(node);
        case 0x23: return ReduceFunctionB(node);
        case 0x24: return ReduceFunctionDef(node);
        case 0x25: return ReduceParametersA(node);
        case 0x26: return ReduceParametersB(node);
        case 0x27: return ReduceParametersC(node);
        case 0x28: return ReduceArgumentsA(node);
        case 0x29: return ReduceArgumentsB(node);
        case 0x2A: return ReduceExprListA(node);
        case 0x2B: return ReduceExprListB(node);
        case 0x2C: return ReduceIf(node);
        case 0x2D: return ReduceElseifA(node);
        case 0x2E: return ReduceElseifB(node);
        case 0x2F: return ReduceElseifC(node);
        case 0x30: return ReduceFor(node);
        case 0x31: return ReduceForStartA(node);
        case 0x32: return ReduceForStartB(node);
        case 0x33: return ReduceForStartC(node);
        case 0x34: return ReduceForStartD(node);
        case 0x35: return ReduceWhileA(node);
        case 0x36: return ReduceWhileB(node);
        case 0x37: return ReduceLoopEnd(node);
        case 0x38: return ReduceLetBlock(node);
        case 0x39: return ReduceBindingsA(node);
        case 0x3A: return ReduceBindingsB(node);
        case 0x3B: return ReduceBinding(node);
        case 0x3C: return ReduceTryBlock(node);
        case 0x3D: return ReduceCatchBlockA(node);
        case 0x3E: return ReduceCatchBlockB(node);
        case 0x3F: return ReduceAssignmentA(node);
        case 0x40: return ReduceAssignmentB(node);
        case 0x41: return ReduceSelfAssignmentA(node);
        case 0x42: return ReduceSelfAssignmentB(node);
        case 0x43: return ReduceSelfAssignmentC(node);
        case 0x44: return ReduceSelfAssignmentD(node);
        case 0x45: return ReduceSelfAssignmentE(node);
        case 0x46: return ReduceSelfAssignmentF(node);
        case 0x47: return ReduceLValueA(node);
        case 0x48: return ReduceLValueB(node);
        case 0x49: return ReduceLValueC(node);
        case 0x4A: return ReduceExpr(node);
        case 0x4B: return ReduceConditionA(node);
        case 0x4C: return ReduceConditionB(node);
        case 0x4D: return ReduceConditionC(node);
        case 0x4E: return ReduceLogicA(node);
        case 0x4F: return ReduceLogicB(node);
        case 0x50: return ReduceComparisonA(node);
        case 0x51: return ReduceComparisonB(node);
        case 0x52: return ReduceComparisonC(node);
        case 0x53: return ReduceComparisonD(node);
        case 0x54: return ReduceComparisonE(node);
        case 0x55: return ReduceComparisonF(node);
        case 0x56: return ReduceComparisonG(node);
        case 0x57: return ReduceComparisonH(node);
        case 0x58: return ReduceComparisonI(node);
        case 0x59: return ReduceArithmeticA(node);
        case 0x5A: return ReduceArithmeticB(node);
        case 0x5B: return ReduceArithmeticC(node);
        case 0x5C: return ReduceTermA(node);
        case 0x5D: return ReduceTermB(node);
        case 0x5E: return ReduceTermC(node);
        case 0x5F: return ReduceTermD(node);
        case 0x60: return ReduceFactorA(node);
        case 0x61: return ReduceFactorB(node);
        case 0x62: return ReduceFactorC(node);
        case 0x63: return ReduceValueA(node);
        case 0x64: return ReduceValueB(node);
        case 0x65: return ReduceValueC(node);
        case 0x66: return ReduceValueD(node);
        case 0x67: return ReducePrimitiveA(node);
        case 0x68: return ReducePrimitiveB(node);
        case 0x69: return ReducePrimitiveC(node);
        case 0x6A: return ReducePrimitiveD(node);
        case 0x6B: return ReducePrimitiveE(node);
        case 0x6C: return ReduceObjectA(node);
        case 0x6D: return ReduceObjectB(node);
        case 0x6E: return ReduceObjectC(node);
        case 0x6F: return ReduceArrayInitA(node);
        case 0x70: return ReduceArrayInitB(node);
        case 0x71: return ReduceDictionaryInitA(node);
        case 0x72: return ReduceDictionaryInitB(node);
        case 0x73: return ReduceDictionaryEntry(node);
    default:
        printf("Unknown production %i.\n", node->production);
        return 1;
    }
}
