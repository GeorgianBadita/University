import { IType } from "../../internal";
export declare function frozen<C>(subType: IType<C, any, any>): IType<C, C, C>;
export declare function frozen<T>(defaultValue: T): IType<T | undefined | null, T, T>;
export declare function frozen<T = any>(): IType<T, T, T>;
/**
 * Returns if a given value represents a frozen type.
 *
 * @param type
 * @returns
 */
export declare function isFrozenType<IT extends IType<T | any, T, T>, T = any>(type: IT): type is IT;
