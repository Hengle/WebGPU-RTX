type textureFormat = string;

module TextureView = {
  type t;

  [@bs.deriving abstract]
  type descriptor = {
    format: textureFormat,
    [@bs.optional]
    dimension: string,
    [@bs.optional]
    aspect: string,
    [@bs.optional]
    baseMipLevel: int,
    [@bs.optional]
    mipLevelCount: int,
    [@bs.optional]
    baseArrayLayer: int,
    [@bs.optional]
    arrayLayerCount: int,
  };
};

module Extend3D = {
  type t = {
    .
    "width": int,
    "height": int,
    "depth": int,
  };
};

module TextureUsage = {
  type t = int;

  [@bs.val] [@bs.scope "GPUTextureUsage"] [@bs.module "webgpu"]
  external copy_src: t = "COPY_SRC";
  [@bs.val] [@bs.scope "GPUTextureUsage"] [@bs.module "webgpu"]
  external copy_dst: t = "COPY_DST";
  [@bs.val] [@bs.scope "GPUTextureUsage"] [@bs.module "webgpu"]
  external sampled: t = "SAMPLED";
  [@bs.val] [@bs.scope "GPUTextureUsage"] [@bs.module "webgpu"]
  external storage: t = "STORAGE";
  [@bs.val] [@bs.scope "GPUTextureUsage"] [@bs.module "webgpu"]
  external output_attachment: t = "OUTPUT_ATTACHMENT";
};

module Texture = {
  type t;

  [@bs.send.pipe: t]
  external createView: TextureView.descriptor => TextureView.t;

  [@bs.deriving abstract]
  type descriptor = {
    size: Extend3D.t,
    arrayLayerCount: int,
    mipLevelCount: int,
    sampleCount: int,
    dimension: string,
    format: textureFormat,
    usage: TextureUsage.t,
  };
};

module SwapChain = {
  type t;

  [@bs.send.pipe: t] external getCurrentTextureView: unit => TextureView.t;
  [@bs.send.pipe: t] external present: unit;
};

module CommandBuffer = {
  type t;
};

module Queue = {
  type t;

  [@bs.send.pipe: t] external submit: array(CommandBuffer.t) => unit;
};

module ShaderStage = {
  type t;

  [@bs.val] [@bs.scope "GPUShaderStage"] [@bs.module "webgpu"]
  external ray_generation: t = "RAY_GENERATION";
  [@bs.val] [@bs.scope "GPUShaderStage"] [@bs.module "webgpu"]
  external ray_closest_hit: t = "RAY_CLOSEST_HIT";
  [@bs.val] [@bs.scope "GPUShaderStage"] [@bs.module "webgpu"]
  external ray_any_hit: t = "RAY_ANY_HIT";
  [@bs.val] [@bs.scope "GPUShaderStage"] [@bs.module "webgpu"]
  external ray_miss: t = "RAY_MISS";
  [@bs.val] [@bs.scope "GPUShaderStage"] [@bs.module "webgpu"]
  external ray_intersection: t = "RAY_INTERSECTION";
  [@bs.val] [@bs.scope "GPUShaderStage"] [@bs.module "webgpu"]
  external compute: t = "COMPUTE";
  [@bs.val] [@bs.scope "GPUShaderStage"] [@bs.module "webgpu"]
  external fragment: t = "FRAGMENT";
  [@bs.val] [@bs.scope "GPUShaderStage"] [@bs.module "webgpu"]
  external vertex: t = "VERTEX";
};

module BufferUsage = {
  type t = int;

  [@bs.val] [@bs.scope "GPUBufferUsage"] [@bs.module "webgpu"]
  external storage: t = "STORAGE";
  [@bs.val] [@bs.scope "GPUBufferUsage"] [@bs.module "webgpu"]
  external uniform: t = "UNIFORM";
  [@bs.val] [@bs.scope "GPUBufferUsage"] [@bs.module "webgpu"]
  external indirect: t = "INDIRECT";
  [@bs.val] [@bs.scope "GPUBufferUsage"] [@bs.module "webgpu"]
  external vertex: t = "VERTEX";
  [@bs.val] [@bs.scope "GPUBufferUsage"] [@bs.module "webgpu"]
  external index: t = "INDEX";
  [@bs.val] [@bs.scope "GPUBufferUsage"] [@bs.module "webgpu"]
  external mapread: t = "MAP_WRITE";
  [@bs.val] [@bs.scope "GPUBufferUsage"] [@bs.module "webgpu"]
  external map_write: t = "MAP_WRITE";
  [@bs.val] [@bs.scope "GPUBufferUsage"] [@bs.module "webgpu"]
  external copy_src: t = "COPY_SRC";
  [@bs.val] [@bs.scope "GPUBufferUsage"] [@bs.module "webgpu"]
  external copy_dst: t = "COPY_DST";
};

module Buffer = {
  type t;

  type descriptor = {
    .
    "size": int,
    "usage": BufferUsage.t,
  };

  [@bs.send.pipe: t]
  external setSubFloat32Data: (int, Js.Typed_array.Float32Array.t) => unit =
    "setSubData";
  [@bs.send.pipe: t]
  external setSubUint8Data: (int, Js.Typed_array.Uint8Array.t) => unit =
    "setSubData";
  [@bs.send.pipe: t]
  external setSubUint32Data: (int, Js.Typed_array.Uint32Array.t) => unit =
    "setSubData";
};

module AccelerationContainerFlag = {
  type t = int;

  [@bs.val]
  [@bs.scope "GPURayTracingAccelerationContainerFlag"]
  [@bs.module "webgpu"]
  external none: t = "NONE";
  [@bs.val]
  [@bs.scope "GPURayTracingAccelerationContainerFlag"]
  [@bs.module "webgpu"]
  external allow_update: t = "ALLOW_UPDATE";
  [@bs.val]
  [@bs.scope "GPURayTracingAccelerationContainerFlag"]
  [@bs.module "webgpu"]
  external prefer_fast_trace: t = "PREFER_FAST_TRACE";
  [@bs.val]
  [@bs.scope "GPURayTracingAccelerationContainerFlag"]
  [@bs.module "webgpu"]
  external prefer_fast_build: t = "PREFER_FAST_BUILD";
  [@bs.val]
  [@bs.scope "GPURayTracingAccelerationContainerFlag"]
  [@bs.module "webgpu"]
  external low_memory: t = "LOW_MEMORY";
};

module AccelerationGeometryFlag = {
  type t = int;

  [@bs.val]
  [@bs.scope "GPURayTracingAccelerationGeometryFlag"]
  [@bs.module "webgpu"]
  external none: t = "NONE";
  [@bs.val]
  [@bs.scope "GPURayTracingAccelerationGeometryFlag"]
  [@bs.module "webgpu"]
  external opaque: t = "OPAQUE";
  [@bs.val]
  [@bs.scope "GPURayTracingAccelerationGeometryFlag"]
  [@bs.module "webgpu"]
  external allow_any_hit: t = "ALLOW_ANY_HIT";
};

module AccelerationInstanceFlag = {
  type t = int;

  [@bs.val]
  [@bs.scope "GPURayTracingAccelerationInstanceFlag"]
  [@bs.module "webgpu"]
  external none: t = "NONE";
  [@bs.val]
  [@bs.scope "GPURayTracingAccelerationInstanceFlag"]
  [@bs.module "webgpu"]
  external triangle_cull_disable: t = "TRIANGLE_CULL_DISABLE";
  [@bs.val]
  [@bs.scope "GPURayTracingAccelerationInstanceFlag"]
  [@bs.module "webgpu"]
  external triangle_front_counterclockwise: t =
    "TRIANGLE_FRONT_COUNTERCLOCKWISE";
  [@bs.val]
  [@bs.scope "GPURayTracingAccelerationInstanceFlag"]
  [@bs.module "webgpu"]
  external force_opaque: t = "FORCE_OPAQUE";
  [@bs.val]
  [@bs.scope "GPURayTracingAccelerationInstanceFlag"]
  [@bs.module "webgpu"]
  external force_no_opaque: t = "FORCE_NO_OPAQUE";
};

module AccelerationContainer = {
  type t;
  // Js.t
  //   // TODO return bigInt type
  //   ({. [@bs.meth] "getHandle": unit => int});

  type geometryVertex = {
    .
    "buffer": Buffer.t,
    "format": string,
    "stride": int,
    "count": int,
  };

  type geometryIndex = {
    .
    "buffer": Buffer.t,
    "format": string,
    "count": int,
  };

  type geometry = {
    .
    "flags": AccelerationGeometryFlag.t,
    "type": string,
    "vertex": geometryVertex,
    "index": geometryIndex,
  };

  type transform3D = {
    .
    "x": float,
    "y": float,
    "z": float,
  };

  type transform = {
    .
    "translation": transform3D,
    "rotation": transform3D,
    "scale": transform3D,
  };

  [@bs.deriving abstract]
  type instance = {
    flags: AccelerationInstanceFlag.t,
    mask: int,
    instanceId: int,
    instanceOffset: int,
    geometryContainer: t,
    [@bs.optional]
    transform,
  };

  [@bs.deriving abstract]
  type descriptor = {
    level: string,
    flags: AccelerationContainerFlag.t,
    [@bs.optional]
    geometries: array(geometry),
    [@bs.optional]
    instances: array(instance),
    [@bs.optional]
    instanceBuffer: Buffer.t,
  };
};

module BindGroupLayout = {
  type t;

  type bindingPoint = int;

  [@bs.deriving abstract]
  type layoutBinding = {
    binding: bindingPoint,
    visibility: ShaderStage.t,
    [@bs.as "type"]
    type_: string,
    [@bs.optional]
    hasDynamicOffset: bool,
  };

  type descriptor = {. "bindings": array(layoutBinding)};
};

module BindGroup = {
  type t;

  [@bs.deriving abstract]
  type binding = {
    [@bs.optional]
    accelerationContainer: AccelerationContainer.t,
    binding: BindGroupLayout.bindingPoint,
    [@bs.optional]
    buffer: Buffer.t,
    [@bs.optional]
    textureView: TextureView.t,
    [@bs.optional]
    offset: int,
    size: int,
  };

  type descriptor = {
    .
    "layout": BindGroupLayout.t,
    "bindings": array(binding),
  };
};

module ShaderModule = {
  type t;

  type descriptor = {. "code": string};
};

module ShaderBindingTable = {
  type t;

  type stage = {
    .
    "module": ShaderModule.t,
    "stage": ShaderStage.t,
  };

  type group = {
    .
    "type": string,
    "generalIndex": int,
    "anyHitIndex": int,
    "closestHitIndex": int,
    "intersectionIndex": int,
  };

  type descriptor = {
    .
    "stages": array(stage),
    "groups": array(group),
  };
};

module Pipeline = {
  type t;

  type layout;

  type layoutConfig = {. "bindGroupLayouts": array(BindGroupLayout.t)};

  module Render = {
    type t;

    [@bs.deriving abstract]
    type vertexStage = {
      [@bs.as "module"]
      module_: ShaderModule.t,
      entryPoint: string,
    };

    [@bs.deriving abstract]
    type fragmentStage = {
      [@bs.as "module"]
      module_: ShaderModule.t,
      entryPoint: string,
    };

    [@bs.deriving abstract]
    type vertexAttribute = {
      shaderLocation: int,
      offset: int,
      format: string,
    };

    [@bs.deriving abstract]
    type vertexBuffer = {
      arrayStride: int,
      [@bs.optional]
      stepMode: string,
      attributes: array(vertexAttribute),
    };

    [@bs.deriving abstract]
    type vertexState = {
      indexFormat: string,
      [@bs.optional]
      vertexBuffers: array(Buffer.t),
    };

    [@bs.deriving abstract]
    type rasterizationState = {
      [@bs.optional]
      frontFace: string,
      [@bs.optional]
      cullMode: string,
    };

    [@bs.deriving abstract]
    type blendDescriptor = {
      [@bs.optional]
      srcFactor: string,
      [@bs.optional]
      dstFactor: string,
      [@bs.optional]
      operation: string,
    };

    [@bs.deriving abstract]
    type colorState = {
      format: textureFormat,
      alphaBlend: blendDescriptor,
      colorBlend: blendDescriptor,
    };

    [@bs.deriving abstract]
    type descriptor = {
      layout,
      [@bs.optional]
      sampleCount: int,
      vertexStage,
      fragmentStage,
      primitiveTopology: string,
      vertexState,
      rasterizationState,
      colorStates: array(colorState),
    };
  };

  module RayTracing = {
    type t;

    [@bs.deriving abstract]
    type rayTracingState = {
      shaderBindingTable: ShaderBindingTable.t,
      maxRecursionDepth: int,
    };

    [@bs.deriving abstract]
    type descriptor = {
      layout,
      rayTracingState,
    };
  };

  module Compute = {
    type t;

    [@bs.deriving abstract]
    type computeStage = {
      [@bs.as "module"]
      module_: ShaderModule.t,
      entryPoint: string,
    };

    [@bs.deriving abstract]
    type descriptor = {
      layout,
      computeStage,
    };
  };
};

module PassEncoder = {
  module Render = {
    type t;

    type clearColor = {
      .
      "r": float,
      "g": float,
      "b": float,
      "a": float,
    };

    type colorAttachment = {
      .
      "clearColor": clearColor,
      "loadOp": string,
      "storeOp": string,
      "attachment": TextureView.t,
    };

    type depthStencilAttachment = {
      .
      "clearColor": clearColor,
      "clearDepth": float,
      "depthLoadOp": string,
      "depthStoreOp": string,
      "clearStencil": int,
      "stencilLoadOp": string,
      "stencilStoreOp": string,
      "attachment": TextureView.t,
    };

    [@bs.deriving abstract]
    type descriptor = {
      colorAttachments: array(colorAttachment),
      [@bs.optional]
      depthStencilAttachments: array(depthStencilAttachment),
    };

    type vertexCount = int;
    type instanceCount = int;
    type firstVertex = int;
    type firstInstance = int;

    [@bs.send.pipe: t] external setPipeline: Pipeline.Render.t => unit;
    [@bs.send.pipe: t]
    external setBindGroup: (BindGroupLayout.bindingPoint, BindGroup.t) => unit;
    [@bs.send.pipe: t] external setVertexBuffer: (int, Buffer.t, int) => unit;
    [@bs.send.pipe: t] external setIndexBuffer: Buffer.t => unit;
    [@bs.send.pipe: t]
    external draw:
      (vertexCount, instanceCount, firstVertex, firstInstance) => unit;
    [@bs.send.pipe: t] external endPass: unit;
  };

  module RayTracing = {
    type t;

    [@bs.deriving abstract]
    type descriptor = {
      [@bs.optional]
      label: string,
    };

    type sbtRayGenerationOffset = int;
    type sbtRayHitOffset = int;
    type sbtRayMissOffset = int;
    type queryWidthDimension = int;
    type queryHeightDimension = int;
    type queryDepthDimension = int;

    [@bs.send.pipe: t] external setPipeline: Pipeline.RayTracing.t => unit;
    [@bs.send.pipe: t]
    external setBindGroup: (BindGroupLayout.bindingPoint, BindGroup.t) => unit;
    [@bs.send.pipe: t]
    external setDynamicBindGroup:
      (BindGroupLayout.bindingPoint, BindGroup.t, int) => unit =
      "setBindGroup";
    [@bs.send.pipe: t]
    external traceRays:
      (
        sbtRayGenerationOffset,
        sbtRayHitOffset,
        sbtRayMissOffset,
        queryWidthDimension,
        queryHeightDimension,
        queryDepthDimension
      ) =>
      unit;
    [@bs.send.pipe: t] external endPass: unit;
  };

  module Compute = {
    type t;

    [@bs.deriving abstract]
    type descriptor = {
      [@bs.optional]
      label: string,
    };

    type x = int;
    type y = int;
    type z = int;

    [@bs.send.pipe: t] external setPipeline: Pipeline.Compute.t => unit;
    [@bs.send.pipe: t]
    external setBindGroup: (BindGroupLayout.bindingPoint, BindGroup.t) => unit;
    [@bs.send.pipe: t] external dispatchX: x => unit = "dispatch";
    [@bs.send.pipe: t] external endPass: unit;
  };
};

module CommandEncoder = {
  type t;

  [@bs.deriving abstract]
  type descriptor = {
    [@bs.optional]
    label: string,
  };

  [@bs.send.pipe: t]
  external beginRenderPass:
    PassEncoder.Render.descriptor => PassEncoder.Render.t;
  [@bs.send.pipe: t]
  external beginRayTracingPass:
    PassEncoder.RayTracing.descriptor => PassEncoder.RayTracing.t;
  [@bs.send.pipe: t]
  external beginComputePass:
    PassEncoder.Compute.descriptor => PassEncoder.Compute.t;
  [@bs.send.pipe: t]
  external buildRayTracingAccelerationContainer:
    AccelerationContainer.t => unit;
  [@bs.send.pipe: t]
  external updateRayTracingAccelerationContainer:
    AccelerationContainer.t => unit;
  [@bs.send.pipe: t] external finish: CommandBuffer.t;
};

module Device = {
  type t;

  [@bs.send.pipe: t] external getQueue: Queue.t;
  [@bs.send.pipe: t]
  external createShaderModule: ShaderModule.descriptor => ShaderModule.t;
  [@bs.send.pipe: t]
  external createPipelineLayout: Pipeline.layoutConfig => Pipeline.layout;
  [@bs.send.pipe: t] external createBuffer: Buffer.descriptor => Buffer.t;
  [@bs.send.pipe: t]
  external createBindGroupLayout:
    BindGroupLayout.descriptor => BindGroupLayout.t;
  [@bs.send.pipe: t]
  external createBindGroup: BindGroup.descriptor => BindGroup.t;
  [@bs.send.pipe: t]
  external createRenderPipeline:
    Pipeline.Render.descriptor => Pipeline.Render.t;
  [@bs.send.pipe: t]
  external createRayTracingPipeline:
    Pipeline.RayTracing.descriptor => Pipeline.RayTracing.t;
  [@bs.send.pipe: t]
  external createComputePipeline:
    Pipeline.Compute.descriptor => Pipeline.Compute.t;
  [@bs.send.pipe: t]
  external createRayTracingShaderBindingTable:
    ShaderBindingTable.descriptor => ShaderBindingTable.t;
  [@bs.send.pipe: t]
  external createRayTracingAccelerationContainer:
    AccelerationContainer.descriptor => AccelerationContainer.t;
  [@bs.send.pipe: t]
  external createCommandEncoder: CommandEncoder.descriptor => CommandEncoder.t;
  [@bs.send.pipe: t] external createTexture: Texture.descriptor => Texture.t;
};

module Context = {
  type t;

  type swapChainConfig = {
    .
    "device": Device.t,
    "format": textureFormat,
  };

  [@bs.send.pipe: t]
  external getSwapChainPreferredFormat:
    Device.t => Js.Promise.t(textureFormat);
  [@bs.send.pipe: t]
  external configureSwapChain: swapChainConfig => SwapChain.t;
};

module Window = {
  type t;

  type descriptor = {
    .
    "width": int,
    "height": int,
    "title": string,
  };

  [@bs.module "webgpu"] [@bs.new]
  external make: descriptor => t = "WebGPUWindow";
  [@bs.send.pipe: t] external getContext: ([@bs.as "webgpu"] _) => Context.t;
  [@bs.send.pipe: t] external pollEvents: unit => unit;
  [@bs.send.pipe: t] external shouldClose: bool;

  [@bs.get] external getWidth: t => int = "width";
  [@bs.get] external getHeight: t => int = "height";
};

module Adapter = {
  type t;

  [@bs.send.pipe: t] external requestDevice: Js.Promise.t(Device.t);
};

module GPU = {
  [@bs.deriving abstract]
  type adapterDescriptor = {
    window: Window.t,
    [@bs.optional]
    preferredBackend: string,
  };

  [@bs.scope "GPU"] [@bs.module "webgpu"]
  external requestAdapter: adapterDescriptor => Js.Promise.t(Adapter.t);
};
