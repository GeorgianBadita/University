/**
 * https://tools.ietf.org/html/rfc6902
 * http://jsonpatch.com/
 */
export interface IJsonPatch {
    readonly op: "replace" | "add" | "remove";
    readonly path: string;
    readonly value?: any;
}
export interface IReversibleJsonPatch extends IJsonPatch {
    readonly oldValue: any;
}
/**
 * Escape slashes and backslashes.
 *
 * http://tools.ietf.org/html/rfc6901
 */
export declare function escapeJsonPath(path: string): string;
/**
 * Unescape slashes and backslashes.
 */
export declare function unescapeJsonPath(path: string): string;
/**
 * Generates a json-path compliant json path from path parts.
 *
 * @param path
 * @returns
 */
export declare function joinJsonPath(path: string[]): string;
/**
 * Splits and decodes a json path into several parts.
 *
 * @param path
 * @returns
 */
export declare function splitJsonPath(path: string): string[];
