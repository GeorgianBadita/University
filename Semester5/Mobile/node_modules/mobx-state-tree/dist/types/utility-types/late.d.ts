import { IAnyType } from "../../internal";
export declare function late<T extends IAnyType>(type: () => T): T;
export declare function late<T extends IAnyType>(name: string, type: () => T): T;
/**
 * Returns if a given value represents a late type.
 *
 * @param type
 * @returns
 */
export declare function isLateType<IT extends IAnyType>(type: IT): type is IT;
