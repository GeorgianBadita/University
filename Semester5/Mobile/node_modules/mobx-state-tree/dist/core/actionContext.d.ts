import { IAnyStateTreeNode, IMiddlewareEvent } from "../internal";
export interface IActionContext {
    /** Event name (action name for actions) */
    readonly name: string;
    /** Event unique id */
    readonly id: number;
    /** Parent action event object */
    readonly parentActionEvent: IMiddlewareEvent | undefined;
    /** Event context (node where the action was invoked) */
    readonly context: IAnyStateTreeNode;
    /** Event tree (root node of the node where the action was invoked) */
    readonly tree: IAnyStateTreeNode;
    /** Event arguments in an array (action arguments for actions) */
    readonly args: any[];
}
/**
 * Returns the currently executing MST action context, or undefined if none.
 */
export declare function getRunningActionContext(): IActionContext | undefined;
/**
 * Returns if the given action context is a parent of this action context.
 */
export declare function isActionContextChildOf(actionContext: IActionContext, parent: number | IActionContext | IMiddlewareEvent): boolean;
/**
 * Returns if the given action context is this or a parent of this action context.
 */
export declare function isActionContextThisOrChildOf(actionContext: IActionContext, parentOrThis: number | IActionContext | IMiddlewareEvent): boolean;
