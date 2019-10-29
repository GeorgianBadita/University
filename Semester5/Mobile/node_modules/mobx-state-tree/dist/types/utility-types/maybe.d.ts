import { IType, IAnyType } from "../../internal";
/** @hidden */
export interface IMaybeIType<IT extends IAnyType, C, O> extends IType<IT["CreationType"] | C, IT["SnapshotType"] | O, IT["TypeWithoutSTN"] | O> {
}
/** @hidden */
export interface IMaybe<IT extends IAnyType> extends IMaybeIType<IT, undefined, undefined> {
}
/** @hidden */
export interface IMaybeNull<IT extends IAnyType> extends IMaybeIType<IT, null | undefined, null> {
}
/**
 * `types.maybe` - Maybe will make a type nullable, and also optional.
 * The value `undefined` will be used to represent nullability.
 *
 * @param type
 * @returns
 */
export declare function maybe<IT extends IAnyType>(type: IT): IMaybe<IT>;
/**
 * `types.maybeNull` - Maybe will make a type nullable, and also optional.
 * The value `null` will be used to represent no value.
 *
 * @param type
 * @returns
 */
export declare function maybeNull<IT extends IAnyType>(type: IT): IMaybeNull<IT>;
