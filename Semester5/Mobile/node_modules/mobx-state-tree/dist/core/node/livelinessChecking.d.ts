/**
 * Defines what MST should do when running into reads / writes to objects that have died.
 * - `"warn"`: Print a warning (default).
 * - `"error"`: Throw an exception.
 * - "`ignore`": Do nothing.
 */
export declare type LivelinessMode = "warn" | "error" | "ignore";
/**
 * Defines what MST should do when running into reads / writes to objects that have died.
 * By default it will print a warning.
 * Use the `"error"` option to easy debugging to see where the error was thrown and when the offending read / write took place
 *
 * @param mode `"warn"`, `"error"` or `"ignore"`
 */
export declare function setLivelinessChecking(mode: LivelinessMode): void;
/**
 * Returns the current liveliness checking mode.
 *
 * @returns `"warn"`, `"error"` or `"ignore"`
 */
export declare function getLivelinessChecking(): LivelinessMode;
/**
 * @deprecated use LivelinessMode instead
 * @hidden
 */
export declare type LivelynessMode = LivelinessMode;
/**
 * @deprecated use setLivelinessChecking instead
 * @hidden
 *
 * Defines what MST should do when running into reads / writes to objects that have died.
 * By default it will print a warning.
 * Use the `"error"` option to easy debugging to see where the error was thrown and when the offending read / write took place
 *
 * @param mode `"warn"`, `"error"` or `"ignore"`
 */
export declare function setLivelynessChecking(mode: LivelinessMode): void;
