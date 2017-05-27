/* parser generator ast walk */
var _DISPATCH;
function Dispatch(subtree) {
	var rule = subtree.rule;
	if (_DISPATCH[rule]) {
		return _DISPATCH[rule](subtree);
	}
}

// <program> -> <top-level-block> 
function Program(subtree) {
	return;
}

// <top-level-block> -> <top-level-stmt> <top-level-block> 
function TopLevelBlockA(subtree) {
	return;
}

// <identifier-list> -> <identifier> , <identifier-list> 
function IdentifierListA(subtree) {
	return;
}

// <identifier-list> -> <identifier> 
function IdentifierListB(subtree) {
	return;
}

// <top-level-stmt> -> import <identifier-list> <endl> 
function TopLevelStmtA(subtree) {
	return;
}

// <top-level-stmt> -> include <string> <endl> 
function TopLevelStmtB(subtree) {
	return;
}

// <top-level-stmt> -> module <identifier> <endl> <block> endmodule <endl> 
function TopLevelStmtC(subtree) {
	return;
}

// <top-level-stmt> -> <stmt> 
function TopLevelStmtD(subtree) {
	return;
}

// <block> -> <stmt> <block> 
function BlockA(subtree) {
	return;
}

// <stmt> -> <expr> <endl> 
function StmtA(subtree) {
	return;
}

// <stmt> -> <assignment> <endl> 
function StmtB(subtree) {
	return;
}

// <stmt> -> <self-assignment> <endl> 
function StmtC(subtree) {
	return;
}

// <stmt> -> <class> <endl> 
function StmtD(subtree) {
	return;
}

// <stmt> -> <function> <endl> 
function StmtE(subtree) {
	return;
}

// <stmt> -> <if> <endl> 
function StmtF(subtree) {
	return;
}

// <stmt> -> <for> <endl> 
function StmtG(subtree) {
	return;
}

// <stmt> -> <while> <endl> 
function StmtH(subtree) {
	return;
}

// <stmt> -> <let-block> <endl> 
function StmtI(subtree) {
	return;
}

// <stmt> -> <try-block> <endl> 
function StmtJ(subtree) {
	return;
}

// <stmt> -> return <endl> 
function StmtK(subtree) {
	return;
}

// <stmt> -> return <expr> <endl> 
function StmtL(subtree) {
	return;
}

// <stmt> -> continue <endl> 
function StmtM(subtree) {
	return;
}

// <stmt> -> break <endl> 
function StmtN(subtree) {
	return;
}

// <stmt> -> throw <expr> <endl> 
function StmtO(subtree) {
	return;
}

// <class> -> class <identifier> <endl> <class-body> 
function ClassA(subtree) {
	return;
}

// <class> -> class <identifier> extends <identifier-list> <endl> <class-body> 
function ClassB(subtree) {
	return;
}

// <class-body> -> <class-block> endclass 
function ClassBody(subtree) {
	return;
}

// <class-block> -> <class-stmt> <class-block> 
function ClassBlockA(subtree) {
	return;
}

// <class-stmt> -> static <assignment> <endl> 
function ClassStmtA(subtree) {
	return;
}

// <class-stmt> -> static <function> <endl> 
function ClassStmtB(subtree) {
	return;
}

// <class-stmt> -> <assignment> <endl> 
function ClassStmtC(subtree) {
	return;
}

// <class-stmt> -> <function> <endl> 
function ClassStmtD(subtree) {
	return;
}

// <function> -> func <identifier> <function-def> 
function FunctionA(subtree) {
	return;
}

// <function> -> func <string> <function-def> 
function FunctionB(subtree) {
	return;
}

// <function-def> -> <parameters> <endl> <block> endfunc 
function FunctionDef(subtree) {
	return;
}

// <parameters> -> ( <identifier-list> ) 
function ParametersA(subtree) {
	return;
}

// <parameters> -> ( ) 
function ParametersB(subtree) {
	return;
}

// <arguments> -> <expr-list> 
function ArgumentsB(subtree) {
	return;
}

// <expr-list> -> <expr> , <expr-list> 
function ExprListA(subtree) {
	return;
}

// <expr-list> -> <expr> 
function ExprListB(subtree) {
	return;
}

// <if> -> if <condition> then <endl> <block> <elseif> 
function If(subtree) {
	return;
}

// <elseif> -> else <endl> <block> endif 
function ElseifA(subtree) {
	return;
}

// <elseif> -> else <if> 
function ElseifB(subtree) {
	return;
}

// <elseif> -> endif 
function ElseifC(subtree) {
	return;
}

// <for> -> for <identifier> <for-start> 
function For(subtree) {
	return;
}

// <for-start> -> = <arithmetic> to <arithmetic> do <endl> <loop-end> 
function ForStartA(subtree) {
	return;
}

// <for-start> -> = <arithmetic> to <arithmetic> step <arithmetic> do <endl> <loop-end> 
function ForStartB(subtree) {
	return;
}

// <for-start> -> in <final> do <endl> <loop-end> 
function ForStartC(subtree) {
	return;
}

// <while> -> while <condition> do <endl> <loop-end> 
function WhileA(subtree) {
	return;
}

// <while> -> do <endl> <block> loop while <condition> 
function WhileB(subtree) {
	return;
}

// <loop-end> -> <block> loop 
function LoopEnd(subtree) {
	return;
}

// <let-block> -> let <bindings> <endl> begin <endl> <block> end 
function LetBlock(subtree) {
	return;
}

// <bindings> -> <binding> , <optendl> <bindings> 
function BindingsA(subtree) {
	return;
}

// <bindings> -> <binding> 
function BindingsB(subtree) {
	return;
}

// <binding> -> <identifier> = <expr> 
function Binding(subtree) {
	return;
}

// <try-block> -> try <endl> <block> <catch-block> 
function TryBlock(subtree) {
	return;
}

// <catch-block> -> catch <l-value> <endl> <block> done 
function CatchBlockA(subtree) {
	return;
}

// <catch-block> -> done 
function CatchBlockB(subtree) {
	return;
}

// <assignment> -> <l-value> = <expr> 
function AssignmentA(subtree) {
	return;
}

// <assignment> -> <l-value> = <object> 
function AssignmentB(subtree) {
	return;
}

// <self-assignment> -> <l-value> += <arithmetic> 
function SelfAssignmentA(subtree) {
	return;
}

// <self-assignment> -> <l-value> -= <arithmetic> 
function SelfAssignmentB(subtree) {
	return;
}

// <self-assignment> -> <l-value> *= <arithmetic> 
function SelfAssignmentC(subtree) {
	return;
}

// <self-assignment> -> <l-value> /= <arithmetic> 
function SelfAssignmentD(subtree) {
	return;
}

// <self-assignment> -> <l-value> ++ 
function SelfAssignmentE(subtree) {
	return;
}

// <self-assignment> -> <l-value> -- 
function SelfAssignmentF(subtree) {
	return;
}

// <l-value> -> <identifier> 
function LValueA(subtree) {
	return;
}

// <l-value> -> <l-value> [ <arithmetic> ] 
function LValueB(subtree) {
	return;
}

// <l-value> -> <l-value> . <identifier> 
function LValueC(subtree) {
	return;
}

// <expr> -> <condition> 
function Expr(subtree) {
	return;
}

// <condition> -> <condition> and <logic> 
function ConditionA(subtree) {
	return;
}

// <condition> -> <condition> or <logic> 
function ConditionB(subtree) {
	return;
}

// <condition> -> <logic> 
function ConditionC(subtree) {
	return;
}

// <logic> -> not <comparison> 
function LogicA(subtree) {
	return;
}

// <logic> -> <comparison> 
function LogicB(subtree) {
	return;
}

// <comparison> -> <comparison> == <arithmetic> 
function ComparisonA(subtree) {
	return;
}

// <comparison> -> <comparison> != <arithmetic> 
function ComparisonB(subtree) {
	return;
}

// <comparison> -> <comparison> < <arithmetic> 
function ComparisonC(subtree) {
	return;
}

// <comparison> -> <comparison> > <arithmetic> 
function ComparisonD(subtree) {
	return;
}

// <comparison> -> <comparison> <= <arithmetic> 
function ComparisonE(subtree) {
	return;
}

// <comparison> -> <comparison> >= <arithmetic> 
function ComparisonF(subtree) {
	return;
}

// <comparison> -> <final> is <l-value> 
function ComparisonG(subtree) {
	return;
}

// <comparison> -> <final> is not <l-value> 
function ComparisonH(subtree) {
	return;
}

// <comparison> -> <arithmetic> 
function ComparisonI(subtree) {
	return;
}

// <arithmetic> -> <arithmetic> + <term> 
function ArithmeticA(subtree) {
	return;
}

// <arithmetic> -> <arithmetic> - <term> 
function ArithmeticB(subtree) {
	return;
}

// <arithmetic> -> <term> 
function ArithmeticC(subtree) {
	return;
}

// <term> -> <term> * <factor> 
function TermA(subtree) {
	return;
}

// <term> -> <term> / <factor> 
function TermB(subtree) {
	return;
}

// <term> -> <term> mod <factor> 
function TermC(subtree) {
	return;
}

// <term> -> <factor> 
function TermD(subtree) {
	return;
}

// <factor> -> - <value> 
function FactorA(subtree) {
	return;
}

// <factor> -> ! <value> 
function FactorB(subtree) {
	return;
}

// <factor> -> <value> 
function FactorC(subtree) {
	return;
}

// <value> -> <primitive> 
function ValueA(subtree) {
	return;
}

// <value> -> <l-value> 
function ValueB(subtree) {
	return;
}

// <value> -> <l-value> ( <arguments> ) 
function ValueC(subtree) {
	return;
}

// <value> -> new <l-value> ( <arguments> ) 
function ValueD(subtree) {
	return;
}

// <value> -> ( <expr> ) 
function ValueE(subtree) {
	return;
}

// <primitive> -> true 
function PrimitiveA(subtree) {
	return;
}

// <primitive> -> false 
function PrimitiveB(subtree) {
	return;
}

// <primitive> -> <integer> 
function PrimitiveC(subtree) {
	return;
}

// <primitive> -> <float> 
function PrimitiveD(subtree) {
	return;
}

// <primitive> -> <string> 
function PrimitiveE(subtree) {
	return;
}

// <object> -> [ <optendl> ] 
function ObjectA(subtree) {
	return;
}

// <object> -> [ <optendl> <array-init> 
function ObjectB(subtree) {
	return;
}

// <object> -> [ <optendl> <dictionary-init> 
function ObjectC(subtree) {
	return;
}

// <array-init> -> <expr> , <optendl> <array-init> 
function ArrayInitA(subtree) {
	return;
}

// <array-init> -> <expr> <optendl> ] 
function ArrayInitB(subtree) {
	return;
}

// <dictionary-init> -> <dictionary-entry> , <optendl> <dictionary-init> 
function DictionaryInitA(subtree) {
	return;
}

// <dictionary-init> -> <dictionary-entry> ] 
function DictionaryInitB(subtree) {
	return;
}

// <dictionary-entry> -> <identifier> : <optendl> <expr> 
function DictionaryEntry(subtree) {
	return;
}

_DISPATCH = [null, Program, TopLevelBlockA, null, IdentifierListA, IdentifierListB, null, null, TopLevelStmtA, TopLevelStmtB, TopLevelStmtC, TopLevelStmtD, BlockA, null, StmtA, StmtB, StmtC, StmtD, StmtE, StmtF, StmtG, StmtH, StmtI, StmtJ, StmtK, StmtL, StmtM, StmtN, StmtO, null, ClassA, ClassB, ClassBody, ClassBlockA, null, ClassStmtA, ClassStmtB, ClassStmtC, ClassStmtD, null, FunctionA, FunctionB, FunctionDef, ParametersA, ParametersB, null, null, ArgumentsB, ExprListA, ExprListB, If, ElseifA, ElseifB, ElseifC, For, ForStartA, ForStartB, ForStartC, WhileA, WhileB, LoopEnd, LetBlock, BindingsA, BindingsB, Binding, TryBlock, CatchBlockA, CatchBlockB, AssignmentA, AssignmentB, SelfAssignmentA, SelfAssignmentB, SelfAssignmentC, SelfAssignmentD, SelfAssignmentE, SelfAssignmentF, LValueA, LValueB, LValueC, Expr, ConditionA, ConditionB, ConditionC, LogicA, LogicB, ComparisonA, ComparisonB, ComparisonC, ComparisonD, ComparisonE, ComparisonF, ComparisonG, ComparisonH, ComparisonI, ArithmeticA, ArithmeticB, ArithmeticC, TermA, TermB, TermC, TermD, FactorA, FactorB, FactorC, ValueA, ValueB, ValueC, ValueD, ValueE, PrimitiveA, PrimitiveB, PrimitiveC, PrimitiveD, PrimitiveE, ObjectA, ObjectB, ObjectC, ArrayInitA, ArrayInitB, DictionaryInitA, DictionaryInitB, DictionaryEntry];

