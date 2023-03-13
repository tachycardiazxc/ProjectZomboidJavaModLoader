#ifndef MODLOADER_CLASSFILESTRUCTURE_H
#define MODLOADER_CLASSFILESTRUCTURE_H

typedef unsigned char u1;
typedef unsigned short u2;
typedef unsigned int u4;

u2 CLASS_FILE_MAJOR_VERSION = 0x61;

typedef struct {
    u2 ACC_PUBLIC;		// Declared public; may be accessed from outside its package.
    u2 ACC_FINAL;		// Declared final; no subclasses allowed.
    u2 ACC_SUPER;		// Treat superclass methods specially when invoked by the invokespecial instruction.
    u2 ACC_INTERFACE;	// Is an interface, not a class.
    u2 ACC_ABSTRACT;	// Declared abstract; must not be instantiated.
    u2 ACC_SYNTHETIC;	// Declared synthetic; not present in the source code.
    u2 ACC_ANNOTATION;	// Declared as an annotation interface.
    u2 ACC_ENUM;		// Declared as an enum class.
    u2 ACC_MODULE;      // Is a module, not a class or interface.
} ClassAccessModifiers;

ClassAccessModifiers classAccessModifiers = {
        0x0001,
        0x0010,
        0x0020,
        0x0200,
        0x0400,
        0x1000,
        0x2000,
        0x4000,
        0x8000
};

typedef struct {
    u2 ACC_PUBLIC;	    //	Declared public; may be accessed from outside its package.
    u2 ACC_PRIVATE;	    // Declared private; accessible only within the defining class and other classes belonging to the same nest (§5.4.4).
    u2 ACC_PROTECTED;	//	Declared protected; may be accessed within subclasses.
    u2 ACC_STATIC;	    //	Declared static.
    u2 ACC_FINAL;	    //	Declared final; never directly assigned to after object construction (JLS §17.5).
    u2 ACC_VOLATILE;	//	Declared volatile; cannot be cached.
    u2 ACC_TRANSIENT;	//	Declared transient; not written or read by a persistent object manager.
    u2 ACC_SYNTHETIC;	//	Declared synthetic; not present in the source code.
    u2 ACC_ENUM;	    //	Declared as an element of an enum class.
} FieldAccessAndPropertyFlags;

FieldAccessAndPropertyFlags fieldAccessAndPropertyFlags = {
        0x0001,
        0x0002,
        0x0004,
        0x0008,
        0x0010,
        0x0040,
        0x0080,
        0x1000,
        0x4000
};

typedef struct {
    u2 ACC_PUBLIC;	        //	Declared public; may be accessed from outside its package.
    u2 ACC_PRIVATE;	        // Declared private; accessible only within the defining class and other classes belonging to the same nest (§5.4.4).
    u2 ACC_PROTECTED;	    //	Declared protected; may be accessed within subclasses.
    u2 ACC_STATIC;	        //	Declared static.
    u2 ACC_FINAL;	        //	Declared final; must not be overridden (§5.4.5).
    u2 ACC_SYNCHRONIZED;	//	Declared synchronized; invocation is wrapped by a monitor use.
    u2 ACC_BRIDGE;	        //	A bridge method, generated by the compiler.
    u2 ACC_VARARGS;	        //	Declared with variable number of arguments.
    u2 ACC_NATIVE;	        //	Declared native; implemented in a language other than the Java programming language.
    u2 ACC_ABSTRACT;	    //	Declared abstract; no implementation is provided.
    u2 ACC_STRICT;	        // In a class file whose major version number is at least 46 and at most 60: Declared strictfp.
    u2 ACC_SYNTHETIC;	    //	Declared synthetic; not present in the source code.
} MethodAccessAndPropertyFlags;

MethodAccessAndPropertyFlags methodAccessAndPropertyFlags = {
        0x0001,
        0x0002,
        0x0004,
        0x0008,
        0x0010,
        0x0020,
        0x0040,
        0x0080,
        0x0100,
        0x0400,
        0x0800,
        0x1000
};

typedef struct {
    u2 ACC_PUBLIC;	    //	Marked or implicitly public in source.
    u2 ACC_PRIVATE; 	//	Marked private in source.
    u2 ACC_PROTECTED;	//	Marked protected in source.
    u2 ACC_STATIC;	    //	Marked or implicitly static in source.
    u2 ACC_FINAL;	    //	Marked or implicitly final in source.
    u2 ACC_INTERFACE;	//	Was an interface in source.
    u2 ACC_ABSTRACT;	//	Marked or implicitly abstract in source.
    u2 ACC_SYNTHETIC;	//	Declared synthetic; not present in the source code.
    u2 ACC_ANNOTATION;	//	Declared as an annotation interface.
    u2 ACC_ENUM;	    //	Declared as an enum class.
} NestedClassAccessAndPropertyFlags;

NestedClassAccessAndPropertyFlags nestedClassAccessAndPropertyFlags = {
        0x0001,
        0x0002,
        0x0004,
        0x0008,
        0x0010,
        0x0200,
        0x0400,
        0x1000,
        0x2000,
        0x4000
};

typedef struct {
    u1 	byteType;	        // signed byte
    u1 	charType;	        // Unicode character code point in the Basic Multilingual Plane, encoded with UTF-16
    u1 	doubleType;	        // double-precision floating-point value
    u1 	floatType;	        // single-precision floating-point value
    u1 	intType;	        // integer
    u1 	longType;	        // long integer
    u1  ClassNameType;      // reference	an instance of class ClassName
    u1 	shortType;	        // signed short
    u1 	booleanType;	    // true or false
    u1 	referenceType;	    // one array dimension
} FieldDescriptors;

FieldDescriptors fieldDescriptors = {
        'B',
        'C',
        'D',
        'F',
        'I',
        'J',
        'L',
        'S',
        'Z',
        '['
};

typedef struct {
    u1 CONSTANT_Class;
    u1 CONSTANT_Fieldref;
    u1 CONSTANT_Methodref;
    u1 CONSTANT_InterfaceMethodref;
    u1 CONSTANT_String;
    u1 CONSTANT_Integer;
    u1 CONSTANT_Float;
    u1 CONSTANT_Long;
    u1 CONSTANT_Double;
    u1 CONSTANT_NameAndType;
    u1 CONSTANT_Utf8;
    u1 CONSTANT_MethodHandle;
    u1 CONSTANT_MethodType;
    u1 CONSTANT_Dynamic;
    u1 CONSTANT_InvokeDynamic;
    u1 CONSTANT_Module;
    u1 CONSTANT_Package;
} ConstantsPoolTags;

ConstantsPoolTags constantsPoolTags = {
        7,
        9,
        10,
        11,
        8,
        3,
        4,
        5,
        6,
        12,
        1,
        15,
        16,
        17,
        18,
        19,
        20
};

struct CONSTANT_Class_info {
    u1 tag;
    u2 name_index;
};

struct CONSTANT_Fieldref_info {
    u1 tag;
    u2 class_index;
    u2 name_and_type_index;
};

struct CONSTANT_Methodref_info {
    u1 tag;
    u2 class_index;
    u2 name_and_type_index;
};

struct CONSTANT_InterfaceMethodref_info {
    u1 tag;
    u2 class_index;
    u2 name_and_type_index;
};

struct cp_info {
    u1 tag;
    u1 *info;
};

struct CONSTANT_String_info {
    u1 tag;
    u2 string_index;
};

struct CONSTANT_Integer_info {
    u1 tag;
    u4 bytes;
};

struct CONSTANT_Float_info {
    u1 tag;
    u4 bytes;
};

struct CONSTANT_Long_info {
    u1 tag;
    u4 high_bytes;
    u4 low_bytes;
};

struct CONSTANT_Double_info {
    u1 tag;
    u4 high_bytes;
    u4 low_bytes;
};

struct CONSTANT_NameAndType_info {
    u1 tag;
    u2 name_index;
    u2 descriptor_index;
};

/*
 * bytes[length]
 * */
struct CONSTANT_Utf8_info {
    u1 tag;
    u2 length;
    u1 *bytes;
};

struct CONSTANT_MethodHandle_info {
    u1 tag;
    u1 reference_kind;
    u2 reference_index;
};

struct CONSTANT_MethodType_info {
    u1 tag;
    u2 descriptor_index;
};

struct CONSTANT_Dynamic_info {
    u1 tag;
    u2 bootstrap_method_attr_index;
    u2 name_and_type_index;
};

struct CONSTANT_InvokeDynamic_info {
    u1 tag;
    u2 bootstrap_method_attr_index;
    u2 name_and_type_index;
};

struct CONSTANT_Module_info {
    u1 tag;
    u2 name_index;
};

struct CONSTANT_Package_info {
    u1 tag;
    u2 name_index;
};

/*
 * info[attribute_length]
 * */
struct attribute_info {
    u2 attribute_name_index;
    u4 attribute_length;
    u1 *info;
};

/*
 * attributes[attributes_count]
 * */
struct field_info {
    u2                      access_flags;
    u2                      name_index;
    u2                      descriptor_index;
    u2                      attributes_count;
    struct attribute_info   *attributes;
};

/*
 * attributes[attributes_count]
 */
struct method_info {
    u2                      access_flags;
    u2                      name_index;
    u2                      descriptor_index;
    u2                      attributes_count;
    struct attribute_info   *attributes;
};

struct ConstantValue_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 constantvalue_index;
};

/*
 * code[code_length]
 * exception_table[exception_table_length]
 * attributes[attributes_count]
 */
struct Code_attribute {
    u2                      attribute_name_index;
    u4                      attribute_length;
    u2                      max_stack;
    u2                      max_locals;
    u4                      code_length;
    u1                      *code;
    u2                      exception_table_length;
    struct {
        u2                  start_pc;
        u2                  end_pc;
        u2                  handler_pc;
        u2                  catch_type;
    }                       *exception_table;
    u2                      attributes_count;
    struct attribute_info   *attributes;
};

u1 ITEM_Top = 0x0;
u1 ITEM_Integer = 0x1;
u1 ITEM_Float = 0x2;
u1 ITEM_Double = 0x3;
u1 ITEM_Long = 0x4;
u1 ITEM_Null = 0x5;
u1 ITEM_UninitializedThis = 0x6;
u1 ITEM_Object = 0x7;
u1 ITEM_Uninitialized = 0x8;

struct Top_variable_info {
    u1 tag; // ITEM_Top
};

struct Integer_variable_info {
    u1 tag; // ITEM_Integer
};

struct Float_variable_info {
    u1 tag; // ITEM_Float
};

struct Double_variable_info {
    u1 tag; // ITEM_Double
};

struct Long_variable_info {
    u1 tag; // ITEM_Long
};

struct Null_variable_info {
    u1 tag; // ITEM_Null
};

struct UninitializedThis_variable_info {
    u1 tag; // ITEM_UninitializedThis
};

struct Object_variable_info {
    u1 tag; // ITEM_Object
    u2 cpool_index;
};

struct Uninitialized_variable_info {
    u1 tag; // ITEM_Uninitialized
    u2 offset;
};

union verification_type_info {
    struct Top_variable_info topVariableInfo;
    struct Integer_variable_info integerVariableInfo;
    struct Float_variable_info floatVariableInfo;
    struct Long_variable_info longVariableInfo;
    struct Double_variable_info doubleVariableInfo;
    struct Null_variable_info nullVariableInfo;
    struct UninitializedThis_variable_info uninitializedThisVariableInfo;
    struct Object_variable_info objectVariableInfo;
    struct Uninitialized_variable_info uninitializedVariableInfo;
};

struct same_frame {
    u1 frame_type;   // SAME 0-63
};

/*
 * stack[1]
 */
struct same_locals_1_stack_item_frame {
    u1 frame_type;   // SAME_LOCALS_1_STACK_ITEM 64-127
    union verification_type_info *stack;
};

/*
 * stack[1]
 */
struct same_locals_1_stack_item_frame_extended {
    u1 frame_type;   // SAME_LOCALS_1_STACK_ITEM_EXTENDED 247
    u2 offset_delta;
    union verification_type_info *stack;
};

struct chop_frame {
    u1 frame_type;   // CHOP 248-250
    u2 offset_delta;
};

struct same_frame_extended {
    u1 frame_type;   // SAME_FRAME_EXTENDED 251
    u2 offset_delta;
};

/*
 * locals[frame_type - 251]
 */
struct append_frame {
    u1 frame_type;   // APPEND 252-254
    u2 offset_delta;
    union verification_type_info *locals;
};

/*
 * locals[number_of_locals]
 * stack[number_of_stack_items]
 */
struct full_frame {
    u1 frame_type;   // FULL_FRAME 255
    u2 offset_delta;
    u2 number_of_locals;
    union verification_type_info *locals;
    u2 number_of_stack_items;
    union verification_type_info *stack;
};

union stack_map_frame {
    struct same_frame sameFrame;
    struct same_locals_1_stack_item_frame sameLocals1StackItemFrame;
    struct same_locals_1_stack_item_frame_extended sameLocals1StackItemFrameExtended;
    struct chop_frame chopFrame;
    struct same_frame_extended sameFrameExtended;
    struct append_frame appendFrame;
    struct full_frame fullFrame;
};

/*
 * entries[number_of_entries]
 */
struct StackMapTable_attribute {
    u2                      attribute_name_index;
    u4                      attribute_length;
    u2                      number_of_entries;
    union stack_map_frame   *entries;
};

/*
 * exception_index_table[number_of_exceptions]
 */
struct Exceptions_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 number_of_exceptions;
    u2 *exception_index_table;
};

/*
 * classes[number_of_classes]
 */
struct InnerClasses_attribute {
    u2          attribute_name_index;
    u4          attribute_length;
    u2          number_of_classes;
    struct {
        u2      inner_class_info_index;
        u2      outer_class_info_index;
        u2      inner_name_index;
        u2      inner_class_access_flags;
    }           *classes;
};

struct EnclosingMethod_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 class_index;
    u2 method_index;
};

struct Synthetic_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
};

struct Signature_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 signature_index;
};

struct SourceFile_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 sourcefile_index;
};

/*
 * debug_extension[attribute_length]
 */
struct SourceDebugExtension_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u1 *debug_extension;
};

/*
 * line_number_table[line_number_table_length]
 */
struct LineNumberTable_attribute {
    u2          attribute_name_index;
    u4          attribute_length;
    u2          line_number_table_length;
    struct {
        u2      start_pc;
        u2      line_number;
    }           *line_number_table;
};

/*
 * local_variable_table[local_variable_table_length]
 */
struct LocalVariableTable_attribute {
    u2          attribute_name_index;
    u4          attribute_length;
    u2          local_variable_table_length;
    struct {
        u2      start_pc;
        u2      length;
        u2      name_index;
        u2      descriptor_index;
        u2      index;
    }           *local_variable_table;
};

/*
 * local_variable_type_table[local_variable_type_table_length]
 */
struct LocalVariableTypeTable_attribute {
    u2          attribute_name_index;
    u4          attribute_length;
    u2          local_variable_type_table_length;
    struct {
        u2      start_pc;
        u2      length;
        u2      name_index;
        u2      signature_index;
        u2      index;
    }           *local_variable_type_table;
};

struct Deprecated_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
};

/*
 * annotation_value_ptr — is pointer to annotation value
 * values[num_values]
 */
struct element_value {
    u1                              tag;
    union {
        u2                          const_value_index;
        struct {
            u2                      type_name_index;
            u2                      const_name_index;
        }                           enum_const_value;
        u2                          class_info_index;
        struct annotation           *annotation_value_ptr;
        struct {
            u2                      num_values;
            struct element_value    *values;
        }                           array_value;
    }                               value;
};

/*
 * element_value_pairs[num_element_value_pairs]
 */
struct annotation {
    u2                          type_index;
    u2                          num_element_value_pairs;
    struct {
        u2                      element_name_index;
        struct element_value    value;
    }                           *element_value_pairs;
};

typedef struct {
    char Byte;	            // byte	const_value_index	CONSTANT_Integer
    char Char;	            // char	const_value_index	CONSTANT_Integer
    char Double;	        // double	const_value_index	CONSTANT_Double
    char Float;	            // float	const_value_index	CONSTANT_Float
    char Int;	            // int	const_value_index	CONSTANT_Integer
    char Long;	            // long	const_value_index	CONSTANT_Long
    char Short;	            // short	const_value_index	CONSTANT_Integer
    char Boolean;	        // boolean	const_value_index	CONSTANT_Integer
    char String;	        // String	const_value_index	CONSTANT_Utf8
    char Enum;	            // Enum class	enum_const_value	Not applicable
    char Class;	            // Class	class_info_index	Not applicable
    char Annotation;	    // Annotation interface	annotation_value	Not applicable
    char Array;	            // Array type	array_value	Not applicable
} InterpretationOfTagValuesAsType;

InterpretationOfTagValuesAsType interpretationOfTagValuesAsType = {
        'B',
        'C',
        'D',
        'F',
        'I',
        'J',
        'S',
        'Z',
        's',
        'e',
        'c',
        '@',
        '['
};

/*
 * annotations[num_annotations]
 */
struct RuntimeVisibleAnnotations_attribute {
    u2                  attribute_name_index;
    u4                  attribute_length;
    u2                  num_annotations;
    struct annotation   *annotations;
};

/*
 * annotations[num_annotations]
 */
struct RuntimeInvisibleAnnotations_attribute {
    u2                  attribute_name_index;
    u4                  attribute_length;
    u2                  num_annotations;
    struct annotation   *annotations;
};

/*
 * annotations[num_annotations]
 * parameter_annotations[num_parameters]
 */
struct RuntimeVisibleParameterAnnotations_attribute {
    u2                      attribute_name_index;
    u4                      attribute_length;
    u1                      num_parameters;
    struct {
        u2                  num_annotations;
        struct annotation   *annotations;
    }                       *parameter_annotations;
};

/*
 * annotations[num_annotations]
 * parameter_annotations[num_parameters]
 */
struct RuntimeInvisibleParameterAnnotations_attribute {
    u2                      attribute_name_index;
    u4                      attribute_length;
    u1                      num_parameters;
    struct {
        u2                  num_annotations;
        struct annotation   *annotations;
    }                       *parameter_annotations;
};

struct type_parameter_target {
    u1 type_parameter_index;
};

struct supertype_target {
    u2 supertype_index;
};

struct type_parameter_bound_target {
    u1 type_parameter_index;
    u1 bound_index;
};

struct empty_target {

};

struct formal_parameter_target {
    u1 formal_parameter_index;
};

struct throws_target {
    u2 throws_type_index;
};

/*
 * table[table_length]
 */
struct localvar_target {
    u2          table_length;
    struct {
        u2      start_pc;
        u2      length;
        u2      index;
    }           *table;
};

struct catch_target {
    u2 exception_table_index;
};

struct offset_target {
    u2 offset;
};

struct type_argument_target {
    u2 offset;
    u1 type_argument_index;
};

/*
 * path[path_length]
 */
struct type_path {
    u1          path_length;
    struct {
        u1      type_path_kind;
        u1      type_argument_index;
    }           *path;
};

typedef struct {
    u1 a;       //	Annotation is deeper in an array type
    u1 b;       //	Annotation is deeper in a nested type
    u1 c;       //	Annotation is on the bound of a wildcard type argument of a parameterized type
    u1 d;       //	Annotation is on a type argument of a parameterized type
} InterpretationOfTypePathKindValues;

InterpretationOfTypePathKindValues interpretationOfTypePathKindValues = {
        0,
        1,
        2,
        3
};

/*
 * element_value_pairs[num_element_value_pairs]
 */
struct type_annotation {
    u1                                          target_type;
    union {
        struct type_parameter_target            typeParameterTarget;
        struct supertype_target                 supertypeTarget;
        struct type_parameter_bound_target      typeParameterBoundTarget;
        struct empty_target                     emptyTarget;
        struct formal_parameter_target          formalParameterTarget;
        struct throws_target                    throwsTarget;
        struct localvar_target                  localvarTarget;
        struct catch_target                     catchTarget;
        struct offset_target                    offsetTarget;
        struct type_argument_target             typeArgumentTarget;
    }                                           target_info;
    struct type_path                            target_path;
    u2                                          type_index;
    u2                                          num_element_value_pairs;
    struct {
        u2                                      element_name_index;
        struct element_value                    value;
    }                                           *element_value_pairs;
};

typedef struct {
    u1 a;    //	type parameter declaration of generic class or interface	type_parameter_target
    u1 b;    //	type parameter declaration of generic method or constructor	type_parameter_target
    u1 c;    //	type in extends or implements clause of class declaration (including the direct superclass or direct superinterface of an anonymous class declaration), or in extends clause of interface declaration	supertype_target
    u1 d;    //	type in bound of type parameter declaration of generic class or interface	type_parameter_bound_target
    u1 e;    //	type in bound of type parameter declaration of generic method or constructor	type_parameter_bound_target
    u1 f;    //  type in field or record component declaration   empty_target
    u1 g;    //	return type of method, or type of newly constructed object	empty_target
    u1 h;    //	receiver type of method or constructor	empty_target
    u1 i;    //	type in formal parameter declaration of method, constructor, or lambda expression	formal_parameter_target
    u1 j;    //	type in throws clause of method or constructor	throws_target
    u1 k;    //	type in local variable declaration	localvar_target
    u1 l;    //	type in resource variable declaration	localvar_target
    u1 m;    //	type in exception parameter declaration	catch_target
    u1 n;    //	type in instanceof expression	offset_target
    u1 o;    //	type in new expression	offset_target
    u1 p;    //	type in method reference expression using ::new	offset_target
    u1 q;    //	type in method reference expression using ::Identifier	offset_target
    u1 r;    //	type in cast expression	type_argument_target
    u1 s;    //	type argument for generic constructor in new expression or explicit constructor invocation statement	type_argument_target
    u1 t;    //	type argument for generic method in method invocation expression	type_argument_target
    u1 u;    //	type argument for generic constructor in method reference expression using ::new	type_argument_target
    u1 v;    //	type argument for generic method in method reference expression using ::Identifier	type_argument_target
} InterpretationOfTargetTypeValues;

InterpretationOfTargetTypeValues interpretationOfTargetTypeValues = {
        0x00,
        0x01,
        0x10,
        0x11,
        0x12,
        0x13,
        0x14,
        0x15,
        0x16,
        0x17,
        0x40,
        0x41,
        0x42,
        0x43,
        0x44,
        0x45,
        0x46,
        0x47,
        0x48,
        0x49,
        0x4A,
        0x4B
};

/*
 * annotations[num_annotations]
 */
struct RuntimeVisibleTypeAnnotations_attribute {
    u2                      attribute_name_index;
    u4                      attribute_length;
    u2                      num_annotations;
    struct type_annotation  *annotations;
};

/*
 * annotations[num_annotations]
 */
struct RuntimeInvisibleTypeAnnotations_attribute {
    u2                      attribute_name_index;
    u4                      attribute_length;
    u2                      num_annotations;
    struct type_annotation  *annotations;
};

struct AnnotationDefault_attribute {
    u2                      attribute_name_index;
    u4                      attribute_length;
    struct element_value    default_value;
};

/*
 * bootstrap_arguments[num_bootstrap_arguments]
 * bootstrap_methods[num_bootstrap_methods]
 */
struct BootstrapMethods_attribute {
    u2          attribute_name_index;
    u4          attribute_length;
    u2          num_bootstrap_methods;
    struct {
        u2      bootstrap_method_ref;
        u2      num_bootstrap_arguments;
        u2      *bootstrap_arguments;
    }           *bootstrap_methods;
};

/*
 * parameters[parameters_count]
 */
struct MethodParameters_attribute {
    u2          attribute_name_index;
    u4          attribute_length;
    u1          parameters_count;
    struct {
        u2      name_index;
        u2      access_flags;
    }           *parameters;
};

/*
 * requires[requires_count]
 * exports_to_index[exports_to_count]
 * exports[exports_count]
 * opens_to_index[opens_to_count]
 * opens[opens_count]
 * uses_index[uses_count]
 * provides_with_index[provides_with_count]
 * provides[provides_count]
 */
struct Module_attribute {
    u2          attribute_name_index;
    u4          attribute_length;
    u2          module_name_index;
    u2          module_flags;
    u2          module_version_index;
    u2          requires_count;
    struct {
        u2      requires_index;
        u2      requires_flags;
        u2      requires_version_index;
    }           *requires;
    u2          exports_count;
    struct {
        u2      exports_index;
        u2      exports_flags;
        u2      exports_to_count;
        u2      *exports_to_index;
    }           *exports;
    u2          opens_count;
    struct {
        u2      opens_index;
        u2      opens_flags;
        u2      opens_to_count;
        u2      *opens_to_index;
    }           *opens;
    u2          uses_count;
    u2          *uses_index;
    u2          provides_count;
    struct {
        u2      provides_index;
        u2      provides_with_count;
        u2      *provides_with_index;
    }           *provides;
};

/*
 * package_index[package_count]
 */
struct ModulePackages_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 package_count;
    u2 *package_index;
};

struct ModuleMainClass_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 main_class_index;
};

struct NestHost_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 host_class_index;
};

/*
 * classes[number_of_classes]
 */
struct NestMembers_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 number_of_classes;
    u2 *classes;
};

/*
 * attributes[attributes_count]
 */
struct record_component_info {
    u2                      name_index;
    u2                      descriptor_index;
    u2                      attributes_count;
    struct attribute_info   *attributes;
};

/*
 * components[components_count]
 */
struct Record_attribute {
    u2                              attribute_name_index;
    u4                              attribute_length;
    u2                              components_count;
    struct record_component_info    *components;
};

/*
 * classes[number_of_classes]
 */
struct PermittedSubclasses_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 number_of_classes;
    u2 *classes;
};

/*
 * cp_info[constant_pool_count - 1]
 * interfaces[interfaces_count]
 * fields[fields_count]
 * methods[methods_count]
 * attributes[attributes_count]
 * */
struct ClassFile {
    u4                          magic;
    u2                          minor_version;
    u2                          major_version;
    u2                          constant_pool_count;
    struct cp_info              *constant_pool;
    u2                          access_flags;
    u2                          this_class;
    u2                          super_class;
    u2                          interfaces_count;
    u2                          *interfaces;
    u2                          fields_count;
    struct field_info           *fields;
    u2                          methods_count;
    struct method_info          *methods;
    u2                          attributes_count;
    struct attribute_info       *attributes;
};

#endif //MODLOADER_CLASSFILESTRUCTURE_H
