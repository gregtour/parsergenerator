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

/* 30. <class> -> class <identifier> <endl> <class-body> */
int ReduceClassA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 4);
    SYNTAX_TREE* identifier1 = node->children[1];
    SYNTAX_TREE* class_body1 = node->children[3];

    int error = 0;
    error = (error ? error : ProcessNode(identifier1));
    error = (error ? error : ProcessNode(class_body1));

    return error;
}

/* 31. <class> -> class <identifier> extends <identifier-list> <endl> <class-body> */
int ReduceClassB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 6);
    SYNTAX_TREE* identifier1 = node->children[1];
    SYNTAX_TREE* identifier_list1 = node->children[3];
    SYNTAX_TREE* class_body1 = node->children[5];

    int error = 0;
    error = (error ? error : ProcessNode(identifier1));
    error = (error ? error : ProcessNode(identifier_list1));
    error = (error ? error : ProcessNode(class_body1));

    return error;
}

/* 32. <class-body> -> <class-block> endclass */
int ReduceClassBody(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* class_block1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(class_block1));

    return error;
}

/* 33. <class-block> -> <class-stmt> <class-block> */
int ReduceClassBlockA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* class_stmt1 = node->children[0];
    SYNTAX_TREE* class_block1 = node->children[1];

    int error = 0;
    error = (error ? error : ProcessNode(class_stmt1));
    error = (error ? error : ProcessNode(class_block1));

    return error;
}

/* 34. <class-block> -> */
int ReduceClassBlockB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 0);

    int error = 0;

    return error;
}

/* 35. <class-stmt> -> static <assignment> <endl> */
int ReduceClassStmtA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* assignment1 = node->children[1];

    int error = 0;
    error = (error ? error : ProcessNode(assignment1));

    return error;
}

/* 36. <class-stmt> -> static <function> <endl> */
int ReduceClassStmtB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* function1 = node->children[1];

    int error = 0;
    error = (error ? error : ProcessNode(function1));

    return error;
}

/* 37. <class-stmt> -> <assignment> <endl> */
int ReduceClassStmtC(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* assignment1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(assignment1));

    return error;
}

/* 38. <class-stmt> -> <function> <endl> */
int ReduceClassStmtD(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* function1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(function1));

    return error;
}

/* 39. <class-stmt> -> <endl> */
int ReduceClassStmtE(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);

    int error = 0;

    return error;
}

/* 40. <function> -> func <identifier> <function-def> */
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

/* 41. <function> -> func <string> <function-def> */
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

/* 42. <function-def> -> <parameters> <endl> <block> endfunc */
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

/* 43. <parameters> -> ( <identifier-list> ) */
int ReduceParametersA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* identifier_list1 = node->children[1];

    int error = 0;
    error = (error ? error : ProcessNode(identifier_list1));

    return error;
}

/* 44. <parameters> -> ( ) */
int ReduceParametersB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);

    int error = 0;

    return error;
}

/* 45. <parameters> -> */
int ReduceParametersC(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 0);

    int error = 0;

    return error;
}

/* 46. <arguments> -> */
int ReduceArgumentsA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 0);

    int error = 0;

    return error;
}

/* 47. <arguments> -> <expr-list> */
int ReduceArgumentsB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* expr_list1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(expr_list1));

    return error;
}

/* 48. <expr-list> -> <expr> , <expr-list> */
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

/* 49. <expr-list> -> <expr> */
int ReduceExprListB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* expr1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(expr1));

    return error;
}

/* 50. <if> -> if <condition> then <endl> <block> <elseif> */
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

/* 51. <elseif> -> else <endl> <block> endif */
int ReduceElseifA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 4);
    SYNTAX_TREE* block1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(block1));

    return error;
}

/* 52. <elseif> -> else <if> */
int ReduceElseifB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* if1 = node->children[1];

    int error = 0;
    error = (error ? error : ProcessNode(if1));

    return error;
}

/* 53. <elseif> -> endif */
int ReduceElseifC(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);

    int error = 0;

    return error;
}

/* 54. <for> -> for <identifier> <for-start> */
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

/* 55. <for-start> -> = <arithmetic> to <arithmetic> do <endl> <loop-end> */
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

/* 56. <for-start> -> = <arithmetic> to <arithmetic> step <arithmetic> do <endl> <loop-end> */
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

/* 57. <for-start> -> in <final> do <endl> <loop-end> */
int ReduceForStartC(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 5);
    SYNTAX_TREE* final1 = node->children[1];
    SYNTAX_TREE* loop_end1 = node->children[4];

    int error = 0;
    error = (error ? error : ProcessNode(final1));
    error = (error ? error : ProcessNode(loop_end1));

    return error;
}

/* 58. <while> -> while <condition> do <endl> <loop-end> */
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

/* 59. <while> -> do <endl> <block> loop while <condition> */
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

/* 60. <loop-end> -> <block> loop */
int ReduceLoopEnd(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* block1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(block1));

    return error;
}

/* 61. <let-block> -> let <bindings> <endl> begin <endl> <block> end */
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

/* 62. <bindings> -> <binding> , <optendl> <bindings> */
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

/* 63. <bindings> -> <binding> */
int ReduceBindingsB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* binding1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(binding1));

    return error;
}

/* 64. <binding> -> <identifier> = <expr> */
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

/* 65. <try-block> -> try <endl> <block> <catch-block> */
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

/* 66. <catch-block> -> catch <l-value> <endl> <block> done */
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

/* 67. <catch-block> -> done */
int ReduceCatchBlockB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);

    int error = 0;

    return error;
}

/* 68. <assignment> -> <l-value> = <expr> */
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

/* 69. <assignment> -> <l-value> = <object> */
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

/* 70. <self-assignment> -> <l-value> += <arithmetic> */
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

/* 71. <self-assignment> -> <l-value> -= <arithmetic> */
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

/* 72. <self-assignment> -> <l-value> *= <arithmetic> */
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

/* 73. <self-assignment> -> <l-value> /= <arithmetic> */
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

/* 74. <self-assignment> -> <l-value> ++ */
int ReduceSelfAssignmentE(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* l_value1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(l_value1));

    return error;
}

/* 75. <self-assignment> -> <l-value> -- */
int ReduceSelfAssignmentF(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* l_value1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(l_value1));

    return error;
}

/* 76. <l-value> -> <identifier> */
int ReduceLValueA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* identifier1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(identifier1));

    return error;
}

/* 77. <l-value> -> <l-value> [ <arithmetic> ] */
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

/* 78. <l-value> -> <l-value> . <identifier> */
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

/* 79. <expr> -> <condition> */
int ReduceExpr(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* condition1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(condition1));

    return error;
}

/* 80. <condition> -> <condition> and <logic> */
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

/* 81. <condition> -> <condition> or <logic> */
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

/* 82. <condition> -> <logic> */
int ReduceConditionC(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* logic1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(logic1));

    return error;
}

/* 83. <logic> -> not <comparison> */
int ReduceLogicA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* comparison1 = node->children[1];

    int error = 0;
    error = (error ? error : ProcessNode(comparison1));

    return error;
}

/* 84. <logic> -> <comparison> */
int ReduceLogicB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* comparison1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(comparison1));

    return error;
}

/* 85. <comparison> -> <comparison> == <arithmetic> */
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

/* 86. <comparison> -> <comparison> != <arithmetic> */
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

/* 87. <comparison> -> <comparison> < <arithmetic> */
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

/* 88. <comparison> -> <comparison> > <arithmetic> */
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

/* 89. <comparison> -> <comparison> <= <arithmetic> */
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

/* 90. <comparison> -> <comparison> >= <arithmetic> */
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

/* 91. <comparison> -> <final> is <l-value> */
int ReduceComparisonG(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* final1 = node->children[0];
    SYNTAX_TREE* l_value1 = node->children[2];

    int error = 0;
    error = (error ? error : ProcessNode(final1));
    error = (error ? error : ProcessNode(l_value1));

    return error;
}

/* 92. <comparison> -> <final> is not <l-value> */
int ReduceComparisonH(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 4);
    SYNTAX_TREE* final1 = node->children[0];
    SYNTAX_TREE* l_value1 = node->children[3];

    int error = 0;
    error = (error ? error : ProcessNode(final1));
    error = (error ? error : ProcessNode(l_value1));

    return error;
}

/* 93. <comparison> -> <arithmetic> */
int ReduceComparisonI(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* arithmetic1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(arithmetic1));

    return error;
}

/* 94. <arithmetic> -> <arithmetic> + <term> */
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

/* 95. <arithmetic> -> <arithmetic> - <term> */
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

/* 96. <arithmetic> -> <term> */
int ReduceArithmeticC(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* term1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(term1));

    return error;
}

/* 97. <term> -> <term> * <factor> */
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

/* 98. <term> -> <term> / <factor> */
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

/* 99. <term> -> <term> mod <factor> */
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

/* 100. <term> -> <factor> */
int ReduceTermD(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* factor1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(factor1));

    return error;
}

/* 101. <factor> -> - <value> */
int ReduceFactorA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* value1 = node->children[1];

    int error = 0;
    error = (error ? error : ProcessNode(value1));

    return error;
}

/* 102. <factor> -> ! <value> */
int ReduceFactorB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* value1 = node->children[1];

    int error = 0;
    error = (error ? error : ProcessNode(value1));

    return error;
}

/* 103. <factor> -> <value> */
int ReduceFactorC(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* value1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(value1));

    return error;
}

/* 104. <value> -> <primitive> */
int ReduceValueA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* primitive1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(primitive1));

    return error;
}

/* 105. <value> -> <l-value> */
int ReduceValueB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* l_value1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(l_value1));

    return error;
}

/* 106. <value> -> <l-value> ( <arguments> ) */
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

/* 107. <value> -> new <l-value> ( <arguments> ) */
int ReduceValueD(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 5);
    SYNTAX_TREE* l_value1 = node->children[1];
    SYNTAX_TREE* arguments1 = node->children[3];

    int error = 0;
    error = (error ? error : ProcessNode(l_value1));
    error = (error ? error : ProcessNode(arguments1));

    return error;
}

/* 108. <value> -> ( <expr> ) */
int ReduceValueE(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* expr1 = node->children[1];

    int error = 0;
    error = (error ? error : ProcessNode(expr1));

    return error;
}

/* 109. <primitive> -> true */
int ReducePrimitiveA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);

    int error = 0;

    return error;
}

/* 110. <primitive> -> false */
int ReducePrimitiveB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);

    int error = 0;

    return error;
}

/* 111. <primitive> -> <integer> */
int ReducePrimitiveC(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* integer1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(integer1));

    return error;
}

/* 112. <primitive> -> <float> */
int ReducePrimitiveD(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* float1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(float1));

    return error;
}

/* 113. <primitive> -> <string> */
int ReducePrimitiveE(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 1);
    SYNTAX_TREE* string1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(string1));

    return error;
}

/* 114. <object> -> [ <optendl> ] */
int ReduceObjectA(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 3);
    SYNTAX_TREE* optendl1 = node->children[1];

    int error = 0;
    error = (error ? error : ProcessNode(optendl1));

    return error;
}

/* 115. <object> -> [ <optendl> <array-init> */
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

/* 116. <object> -> [ <optendl> <dictionary-init> */
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

/* 117. <array-init> -> <expr> , <optendl> <array-init> */
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

/* 118. <array-init> -> <expr> <optendl> ] */
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

/* 119. <dictionary-init> -> <dictionary-entry> , <optendl> <dictionary-init> */
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

/* 120. <dictionary-init> -> <dictionary-entry> ] */
int ReduceDictionaryInitB(SYNTAX_TREE* node)
{
    Assert(node->numChildren == 2);
    SYNTAX_TREE* dictionary_entry1 = node->children[0];

    int error = 0;
    error = (error ? error : ProcessNode(dictionary_entry1));

    return error;
}

/* 121. <dictionary-entry> -> <identifier> : <optendl> <expr> */
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
        case 0x1E: return ReduceClassA(node);
        case 0x1F: return ReduceClassB(node);
        case 0x20: return ReduceClassBody(node);
        case 0x21: return ReduceClassBlockA(node);
        case 0x22: return ReduceClassBlockB(node);
        case 0x23: return ReduceClassStmtA(node);
        case 0x24: return ReduceClassStmtB(node);
        case 0x25: return ReduceClassStmtC(node);
        case 0x26: return ReduceClassStmtD(node);
        case 0x27: return ReduceClassStmtE(node);
        case 0x28: return ReduceFunctionA(node);
        case 0x29: return ReduceFunctionB(node);
        case 0x2A: return ReduceFunctionDef(node);
        case 0x2B: return ReduceParametersA(node);
        case 0x2C: return ReduceParametersB(node);
        case 0x2D: return ReduceParametersC(node);
        case 0x2E: return ReduceArgumentsA(node);
        case 0x2F: return ReduceArgumentsB(node);
        case 0x30: return ReduceExprListA(node);
        case 0x31: return ReduceExprListB(node);
        case 0x32: return ReduceIf(node);
        case 0x33: return ReduceElseifA(node);
        case 0x34: return ReduceElseifB(node);
        case 0x35: return ReduceElseifC(node);
        case 0x36: return ReduceFor(node);
        case 0x37: return ReduceForStartA(node);
        case 0x38: return ReduceForStartB(node);
        case 0x39: return ReduceForStartC(node);
        case 0x3A: return ReduceWhileA(node);
        case 0x3B: return ReduceWhileB(node);
        case 0x3C: return ReduceLoopEnd(node);
        case 0x3D: return ReduceLetBlock(node);
        case 0x3E: return ReduceBindingsA(node);
        case 0x3F: return ReduceBindingsB(node);
        case 0x40: return ReduceBinding(node);
        case 0x41: return ReduceTryBlock(node);
        case 0x42: return ReduceCatchBlockA(node);
        case 0x43: return ReduceCatchBlockB(node);
        case 0x44: return ReduceAssignmentA(node);
        case 0x45: return ReduceAssignmentB(node);
        case 0x46: return ReduceSelfAssignmentA(node);
        case 0x47: return ReduceSelfAssignmentB(node);
        case 0x48: return ReduceSelfAssignmentC(node);
        case 0x49: return ReduceSelfAssignmentD(node);
        case 0x4A: return ReduceSelfAssignmentE(node);
        case 0x4B: return ReduceSelfAssignmentF(node);
        case 0x4C: return ReduceLValueA(node);
        case 0x4D: return ReduceLValueB(node);
        case 0x4E: return ReduceLValueC(node);
        case 0x4F: return ReduceExpr(node);
        case 0x50: return ReduceConditionA(node);
        case 0x51: return ReduceConditionB(node);
        case 0x52: return ReduceConditionC(node);
        case 0x53: return ReduceLogicA(node);
        case 0x54: return ReduceLogicB(node);
        case 0x55: return ReduceComparisonA(node);
        case 0x56: return ReduceComparisonB(node);
        case 0x57: return ReduceComparisonC(node);
        case 0x58: return ReduceComparisonD(node);
        case 0x59: return ReduceComparisonE(node);
        case 0x5A: return ReduceComparisonF(node);
        case 0x5B: return ReduceComparisonG(node);
        case 0x5C: return ReduceComparisonH(node);
        case 0x5D: return ReduceComparisonI(node);
        case 0x5E: return ReduceArithmeticA(node);
        case 0x5F: return ReduceArithmeticB(node);
        case 0x60: return ReduceArithmeticC(node);
        case 0x61: return ReduceTermA(node);
        case 0x62: return ReduceTermB(node);
        case 0x63: return ReduceTermC(node);
        case 0x64: return ReduceTermD(node);
        case 0x65: return ReduceFactorA(node);
        case 0x66: return ReduceFactorB(node);
        case 0x67: return ReduceFactorC(node);
        case 0x68: return ReduceValueA(node);
        case 0x69: return ReduceValueB(node);
        case 0x6A: return ReduceValueC(node);
        case 0x6B: return ReduceValueD(node);
        case 0x6C: return ReduceValueE(node);
        case 0x6D: return ReducePrimitiveA(node);
        case 0x6E: return ReducePrimitiveB(node);
        case 0x6F: return ReducePrimitiveC(node);
        case 0x70: return ReducePrimitiveD(node);
        case 0x71: return ReducePrimitiveE(node);
        case 0x72: return ReduceObjectA(node);
        case 0x73: return ReduceObjectB(node);
        case 0x74: return ReduceObjectC(node);
        case 0x75: return ReduceArrayInitA(node);
        case 0x76: return ReduceArrayInitB(node);
        case 0x77: return ReduceDictionaryInitA(node);
        case 0x78: return ReduceDictionaryInitB(node);
        case 0x79: return ReduceDictionaryEntry(node);
    default:
        printf("Unknown production %i.\n", node->production);
        return 1;
    }
}
