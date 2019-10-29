import { IAnyType, ExtractCSTWithSTN } from "../../internal";
/** Validation context entry, this is, where the validation should run against which type */
export interface IValidationContextEntry {
    /** Subpath where the validation should be run, or an empty string to validate it all */
    path: string;
    /** Type to validate the subpath against */
    type: IAnyType;
}
/** Array of validation context entries */
export declare type IValidationContext = IValidationContextEntry[];
/** Type validation error */
export interface IValidationError {
    /** Validation context */
    context: IValidationContext;
    /** Value that was being validated, either a snapshot or an instance */
    value: any;
    /** Error message */
    message?: string;
}
/** Type validation result, which is an array of type validation errors */
export declare type IValidationResult = IValidationError[];
/**
 * Run's the typechecker for the given type on the given value, which can be a snapshot or an instance.
 * Throws if the given value is not according the provided type specification.
 * Use this if you need typechecks even in a production build (by default all automatic runtime type checks will be skipped in production builds)
 *
 * @param type Type to check against.
 * @param value Value to be checked, either a snapshot or an instance.
 */
export declare function typecheck<IT extends IAnyType>(type: IT, value: ExtractCSTWithSTN<IT>): void;
