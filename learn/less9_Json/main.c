#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <stdbool.h>




typedef enum {
    JSON_NULL,
    JSON_BOOLEAN,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} JsonType;


typedef struct JsonValue {
    JsonType type;
    union 
    {
        int boolean;
        double number;
        char *string;
        struct 
        {
            struct JsonValue *values;
            size_t count;
        } array;
        struct 
        {
            char **keys;
            struct JsonValue *values;
            size_t count;
        } object;
    } value;
} JsonValue;


JsonValue *parse_json(const char **json);
void free_json_value(JsonValue *json_value);




static void skip_whitespace(const char **json) {
    while (isspace(**json)) {
        (*json)++;
    }
}

JsonValue *parse_null(const char **json) {
    skip_whitespace(json);
    if (strncmp(*json, "null", 4) == 0) {
        JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
        value->type = JSON_NULL;
        *json += 4;
        return value;
    }
    return NULL;
}

JsonValue *parse_boolean(const char **json) {
    skip_whitespace(json);
    JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
    if (strncmp(*json, "true", 4) == 0) {
        value->type = JSON_BOOLEAN;
        value->value.boolean = true;
        *json += 4;
    } else if (strncmp(*json, "false", 5) == 0) {
        value->type = JSON_BOOLEAN;
        value->value.boolean = false;
        *json += 5;
    } else {
        free(value);
        return NULL;
    }
    return value;
}

JsonValue *parse_number(const char **json) {
    skip_whitespace(json);
    char *end;

    //chuyen doi doan chuoi tu json thành double sau đó end trỏ đến ký tự cuối cùng kế tiếp sau giá trị số.
    double num = strtod(*json, &end);
    if (end != *json) {
        JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
        value->type = JSON_NUMBER;
        value->value.number = num;
        *json = end;
        return value;
    }
    return NULL;
}

JsonValue *parse_string(const char **json) {
    skip_whitespace(json);


    if (**json == '\"') {   //"
        (*json)++;
        const char *start = *json;
        while (**json != '\"' && **json != '\0') 
        {
            (*json)++;
        }
        if (**json == '\"') {
            size_t length = *json - start; // 3
            char *str = (char *) malloc((length + 1) * sizeof(char));
            strncpy(str, start, length);
            str[length] = '\0';


            JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
            value->type = JSON_STRING;
            value->value.string = str;
            (*json)++;
            return value;
        }
    }
    return NULL;
}



JsonValue *parse_array(const char **json) {
    skip_whitespace(json);
    if (**json == '[') {
        (*json)++;
        skip_whitespace(json);

        JsonValue *array_value = (JsonValue *)malloc(sizeof(JsonValue));
        array_value->type = JSON_ARRAY;
        array_value->value.array.count = 0;
        array_value->value.array.values = NULL;

        /*
        double arr[2] = {};
        arr[0] = 30;
        arr[1] = 70;
        */

       // [1 ,  2 ,  3 ,  4,  5]
        while (**json != ']' && **json != '\0') {
            JsonValue *element = parse_json(json); // 70
            if (element) {
                array_value->value.array.count++;
                array_value->value.array.values = (JsonValue *)realloc(array_value->value.array.values, array_value->value.array.count * sizeof(JsonValue));
                array_value->value.array.values[array_value->value.array.count - 1] = *element;
                free(element);
            } else {
                break;
            }
            skip_whitespace(json);
            if (**json == ',') {
                (*json)++;
            }
        }
        if (**json == ']') {
            (*json)++;
            return array_value;
        } else {
            free_json_value(array_value);
            return NULL;
        }
    }
    return NULL;
}

JsonValue *parse_object(const char **json) {
    skip_whitespace(json);
    if (**json == '{') {
        (*json)++;
        skip_whitespace(json);

        JsonValue *object_value = (JsonValue *)malloc(sizeof(JsonValue));
        object_value->type = JSON_OBJECT;
        object_value->value.object.count = 0;
        object_value->value.object.keys = NULL;
        object_value->value.object.values = NULL;



        while (**json != '}' && **json != '\0') {
            JsonValue *key = parse_string(json);
            if (key) {
                skip_whitespace(json);
                if (**json == ':') {
                    (*json)++;
                    JsonValue *value = parse_json(json);
                    if (value) {
                        object_value->value.object.count++;
                        object_value->value.object.keys = (char **)realloc(object_value->value.object.keys, object_value->value.object.count * sizeof(char *));
                        object_value->value.object.keys[object_value->value.object.count - 1] = key->value.string;

                        object_value->value.object.values = (JsonValue *)realloc(object_value->value.object.values, object_value->value.object.count * sizeof(JsonValue));
                        object_value->value.object.values[object_value->value.object.count - 1] = *value;
                        free(value);
                    } else {
                        free_json_value(key);
                        break;
                    }
                } else {
                    free_json_value(key);
                    break;
                }
            } else {
                break;
            }
            skip_whitespace(json);
            if (**json == ',') {
                (*json)++;
            }
        }
        if (**json == '}') {
            (*json)++;
            return object_value;
        } else {
            free_json_value(object_value);
            return NULL;
        }
    }
    return NULL;
}


JsonValue *parse_json(const char **json) { 
    while (isspace(**json)) {
        (*json)++;
    }


    switch (**json) {
        case 'n':
            return parse_null(json);
        case 't':
        case 'f':
            return parse_boolean(json);
        case '\"':
            return parse_string(json);
        case '[':
            return parse_array(json);
        case '{':
            return parse_object(json);
        default:
            if (isdigit(**json) || **json == '-')           // kiểm tra json có phải số hoặc dấu - (số âm) không.
            {
                return parse_number(json);
            } else {
                // Lỗi phân tích cú pháp
                return NULL;
            }
    }
}



////////////




/////////////

void free_json_value(JsonValue *json_value) {
    if (json_value == NULL) {
        return;
    }

    switch (json_value->type) {
        case JSON_STRING:
            free(json_value->value.string);
            break;

        case JSON_ARRAY:
            for (size_t i = 0; i < json_value->value.array.count; i++) {
                free_json_value(&json_value->value.array.values[i]);
            }
            free(json_value->value.array.values);
            break;

        case JSON_OBJECT:
            for (size_t i = 0; i < json_value->value.object.count; i++) {
                free(json_value->value.object.keys[i]);
                free_json_value(&json_value->value.object.values[i]);
            }
            free(json_value->value.object.keys);
            free(json_value->value.object.values);
            break;

        default:
            break;
    }
}



void test(JsonValue* json_value){
    if (json_value != NULL && json_value->type == JSON_OBJECT) {
        // Truy cập giá trị của các trường trong đối tượng JSON
        size_t num_fields = json_value->value.object.count;
        size_t num_fields2 = json_value->value.object.values->value.object.count;
        for (size_t i = 0; i < num_fields; ++i) {

            char* key = json_value->value.object.keys[i];
            JsonValue* value = &json_value->value.object.values[i];

            JsonType type = (int)(json_value->value.object.values[i].type);


            if(type == JSON_STRING){
                printf("%s: %s\n", key, value->value.string);
            }

            if(type == JSON_NUMBER){
                printf("%s: %f\n", key, value->value.number);
            }

            if(type == JSON_BOOLEAN){
                printf("%s: %s\n", key, value->value.boolean ? "True":"False");
            }

            if(type == JSON_OBJECT){
                printf("%s: \n", key);
                test(value);
            }

            if(type == JSON_ARRAY){
                printf("%s: ", key);
                for (int i = 0; i < value->value.array.count; i++)
                {
                   test(value->value.array.values + i);
                } 
                printf("\n");
            }

  
        }

     
    }
    else 
    {
            if(json_value->type == JSON_STRING){
                printf("%s ", json_value->value.string);
            }

            if(json_value->type == JSON_NUMBER){
                printf("%f ", json_value->value.number);
            }

            if(json_value->type == JSON_BOOLEAN){
                printf("%s ", json_value->value.boolean ? "True":"False");
            }

            if(json_value->type == JSON_OBJECT){
                printf("%s: \n", json_value->value.object.keys);
                test(json_value->value.object.values);
                           
            }
    }

}




int main(int argc, char const *argv[])
{

    // JsonValue test;
    // test.type = JSON_OBJECT;
    // test.value.object.keys = "name";
    // test.value.object.values->type = JSON_STRING;



     // Chuỗi JSON đầu vào
    
    const char* json_str = "{"
                        "\"1001\":{"                    //0.0
                          "\"SoPhong\":3,"              //0.1
                          "\"NguoiThue\":{"             //0.1.0
                            "\"Ten\":\"Nguyen Van A\","  //0.1.1
                            "\"CCCD\":\"1920517781\","  //0.1.2
                            "\"Tuoi\":26,"              //0.1.3
                            "\"ThuongTru\":{"           //0.1.3.0
                              "\"Duong\":\"73 Ba Huyen Thanh Quan\","   //0.1.3.1
                              "\"Phuong_Xa\":\"Phuong 6\","             //0.1.3.2
                              "\"Tinh_TP\":\"Ho Chi Minh\""             //0.1.3.3
                            "}"                                         //0.1.4
                          "},"                                          //0.2
                          "\"SoNguoiO\":{"                              //0.2.0
                            "\"1\":\"Nguyen Van A\","                   //0.2.1
                            "\"2\":\"Nguyen Van B\","                   //0.2.2
                            "\"3\":\"Nguyen Van C\""                    //0.2.3
                          "},"                                          //0.3
                          "\"TienDien\": [24, 56, 98],"                 //0.4
                          "\"TienNuoc\":30.000"                         //0.5
                        "},"                                            //1               
                        "\"1002\":{"                                    //1.0
                          "\"SoPhong\":5,"                              //1.1
                          "\"NguoiThue\":{"                             //1.1.0
                            "\"Ten\":\"Phan Hoang Trung\","             //1.1.1
                            "\"CCCD\":\"012345678912\","                //1.1.2
                            "\"Tuoi\":24,"                              //1.1.3
                            "\"ThuongTru\":{"                           //1.1.3.0
                              "\"Duong\":\"53 Le Dai Hanh\","           //1.1.3.1
                              "\"Phuong_Xa\":\"Phuong 11\","            //1.1.3.2
                              "\"Tinh_TP\":\"Ho Chi Minh\""             //1.1.3.3
                            "}"                                         //1.1.4
                          "},"                                          //1.2
                          "\"SoNguoiO\":{"                              //1.2.0
                            "\"1\":\"Phan Van Nhat\","                  //1.2.1
                            "\"2\":\"Phan Van Nhi\","                   //1.2.2
                            "\"2\":\"Phan Van Tam\","                   //1.2.3
                            "\"3\":\"Phan Van Tu\""                     //1.2.4
                          "},"                                          //1.3
                          "\"TienDien\":23.000,"                        //1.4
                          "\"TienNuoc\":40.000"                         //1.5
                        "}"                                             //2
                      "}";                                              //END
    

    // Phân tích cú pháp chuỗi JSON
    JsonValue* json_value = parse_json(&json_str);



   test(json_value);

    // Kiểm tra kết quả phân tích cú pháp

       // Giải phóng bộ nhớ được cấp phát cho JsonValue
    free_json_value(json_value);
    
    

        //printf("test = %x", '\"');

       // hienthi(5);
    
    return 0;
}
