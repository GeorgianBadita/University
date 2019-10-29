import { IType, IAnyType, ExtractCSTWithSTN } from "../../internal";
/** @hidden */
export declare type ValidOptionalValue = string | boolean | number | null | undefined;
/** @hidden */
export declare type ValidOptionalValues = [ValidOptionalValue, ...ValidOptionalValue[]];
/** @hidden */
export declare type OptionalDefaultValueOrFunction<IT extends IAnyType> = IT["CreationType"] | IT["SnapshotType"] | (() => ExtractCSTWithSTN<IT>);
/** @hidden */
export interface IOptionalIType<IT extends IAnyType, OptionalVals extends ValidOptionalValues> extends IType<IT["CreationType"] | OptionalVals[number], IT["SnapshotType"], IT["TypeWithoutSTN"]> {
}
export declare function optional<IT extends IAnyType>(type: IT, defaultValueOrFunction: OptionalDefaultValueOrFunction<IT>): IOptionalIType<IT, [undefined]>;
export declare function optional<IT extends IAnyType, OptionalVals extends ValidOptionalValues>(type: IT, defaultValueOrFunction: OptionalDefaultValueOrFunction<IT>, optionalValues: OptionalVals): IOptionalIType<IT, OptionalVals>;
/**
 * Returns if a value represents an optional type.
 *
 * @template IT
 * @param type
 * @returns
 */
export declare function isOptionalType<IT extends IAnyType>(type: IT): type is IT;
