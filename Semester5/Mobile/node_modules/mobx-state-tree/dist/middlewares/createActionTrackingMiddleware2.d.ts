import { IMiddlewareHandler, IActionContext } from "../internal";
export interface IActionTrackingMiddleware2Call<TEnv> extends Readonly<IActionContext> {
    env: TEnv | undefined;
    readonly parentCall?: IActionTrackingMiddleware2Call<TEnv>;
}
export interface IActionTrackingMiddleware2Hooks<TEnv> {
    filter?: (call: IActionTrackingMiddleware2Call<TEnv>) => boolean;
    onStart: (call: IActionTrackingMiddleware2Call<TEnv>) => void;
    onFinish: (call: IActionTrackingMiddleware2Call<TEnv>, error?: any) => void;
}
/**
 * Convenience utility to create action based middleware that supports async processes more easily.
 * The flow is like this:
 * - for each action: if filter passes -> `onStart` -> (inner actions recursively) -> `onFinish`
 *
 * Example: if we had an action `a` that called inside an action `b1`, then `b2` the flow would be:
 * - `filter(a)`
 * - `onStart(a)`
 *   - `filter(b1)`
 *   - `onStart(b1)`
 *   - `onFinish(b1)`
 *   - `filter(b2)`
 *   - `onStart(b2)`
 *   - `onFinish(b2)`
 * - `onFinish(a)`
 *
 * The flow is the same no matter if the actions are sync or async.
 *
 * See the `atomic` middleware for an example
 *
 * @param hooks
 * @returns
 */
export declare function createActionTrackingMiddleware2<TEnv = any>(middlewareHooks: IActionTrackingMiddleware2Hooks<TEnv>): IMiddlewareHandler;
